
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h>  /*htons*/
#include <unistd.h>     /*close*/
#include <fcntl.h>      /*fcntl*/
#include <sys/select.h> /*select*/
#include <string>
#include <iostream>
#include <cstring>
#include <list>


#include "tcp_server.hpp"
#include "tcp_selector.hpp"
#include "handler.hpp"
#include "server_handler_string.hpp"
#include "tcp_client_socket.hpp"

#include "adress.hpp"


namespace net{

TcpServer::TcpServer(Adress const& a_adress, Handler* a_handler)
: m_socket()
, m_clients()
, m_handler(a_handler)
{
    m_socket.bind(a_adress.get_ip(), a_adress.get_port());
    m_socket.listen();
}


TcpServer::~TcpServer()
{
    for (auto client :m_clients)
    {
        delete client;
    }
}


void TcpServer::run(Selector* a_selector)
{
   a_selector->select();
}



int TcpServer::add_new_client()
{
    std::cout << "\nchecking for new clients...\n";
    TcpClientSocket* p = m_socket.accept();
    m_clients.push_back(p);

    auto last = m_clients.rbegin();
    int sock = (*last)->get_socket();
    std::cout << "client connected at socket: " << sock << '\n';

    return sock;
}



void TcpServer::remove_client(std::list<TcpClientSocket*>::iterator a_it)
{
   m_clients.erase(a_it);
}


bool TcpServer::check_exsist_client(TcpClientSocket* a_client_socket)
{   	
    std::cout << "\nchecking for new messages...\n";

	std::vector<uint8_t> buffer(4096, 0);
	int expectedDataLen = buffer.size();

    int client_socket_num = a_client_socket -> get_socket();
	int readBytes = recv(client_socket_num, buffer.data(), expectedDataLen, 0);
    std::cout << "\nreadBytes: " << readBytes << '\n';

	if(readBytes <= 0)
	{
        std::cout << "server recieve failed\n";

		return false;
	}
	buffer[readBytes] = '\0';

	for(auto c : buffer)
	{
		std::cout << c;
	}
	std::cout << '\n';
	call_back(buffer, a_client_socket);
	return true;
}



void TcpServer::send(int a_client_socket, std::vector<uint8_t> const&  a_data)
{
    int sent_bytes = ::send(a_client_socket, a_data.data(), a_data.size(), 0);
    std::cout << "sentBytes to client at socket: " << a_client_socket << ", " << sent_bytes << '\n';

	    if(sent_bytes < 0) 
        {
            std::cout << "server send failed\n";
            throw "send failed";
        }
	
}

int TcpServer::get_socket()
{
    return m_socket.get_socket(); 
}

std::list<TcpClientSocket*> TcpServer::get_clients()
{
    return m_clients;
}


void TcpServer::call_back(std::vector<uint8_t> const&  a_message, TcpClientSocket* a_client_socket)
{
    m_handler->handle(a_message, a_message.size(), a_client_socket);
}


}//namespace net


