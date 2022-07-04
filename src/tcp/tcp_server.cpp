
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
#include "tcp_server_socket.hpp"

namespace net{

TcpServer::TcpServer(const char* a_ip, int a_port)
: m_socket()
, m_clients()
{
    m_socket.bind(a_ip, a_port);
    m_socket.listen();
    m_socket.accept();
    //selector
}


TcpServer::~TcpServer()
{
    for (auto client :m_clients)
    {
        delete client;
    }
}

/*
void TcpServer::run()
{
    char message[2000];

    while(true)
    {
        int read_bytes = recv(m_socket, message, sizeof(massage), 0);
        if(read_bytes < 0)
        {
            //throw recieve failed
        }
        else if(read_bytes == 0)
        {
            break;
        }
        message[strlen(message)] = '\0';

        std::cout << "massage from client:" << message << '\n';

        //char[2000] answer = get_response(message);

        char[2000] answer = "answer";

        if(read_bytes > 0)
        {
            int send_bytes = send(m_socket, answer, strlen(message), 0);

            if(send_bytes)
            {
                //throw send failed;
            }

        }
    }
}*/



int TcpServer::add_new_client()
{
    TcpClientSocket* p = m_socket.accept();
    m_clients.push_back(p);

    auto last = m_clients.rbegin();
    int sock = (*last)->get_socket();

    return sock;
}

void TcpServer::remove_client(std::list<TcpClientSocket*>::iterator a_it)
{
   m_clients.erase(a_it);
}

bool TcpServer::check_exsist_client(int a_client_socket)
{
	std::vector<uint8_t> buffer;
	int expectedDataLen = buffer.size();

	int readBytes = recv(a_client_socket, &buffer, expectedDataLen, 0);

	if(readBytes <= 0)
	{
		return false;
	}
	buffer[readBytes] = '\0';
	//call_back(buffer);
	return true;
}



void TcpServer::send(int a_clientSocket, std::vector<uint8_t> const&  a_data)
{
    int sentBytes = ::send(a_clientSocket, a_data.data(), a_data.size(), 0);

	    if(sentBytes < 0) 
        {
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


}//namespace net


