#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h>  /*htons*/
#include <unistd.h>     /*close*/
#include <fcntl.h>      /*fcntl*/
#include <sys/select.h> /*select*/
#include <string>
#include <iostream>
#include <cstring>


#include "tcp_client_socket.hpp"
#include "adress.hpp"


namespace net{


TcpClientSocket::TcpClientSocket()
:m_socket(create_socket())
{
}



TcpClientSocket::TcpClientSocket(int a_socket)
:m_socket(a_socket)
{
    if(socket < 0)
	{
        std::cout << "socket initialization failed\n";
		throw "socket not initialized";
	}
}

TcpClientSocket::~TcpClientSocket()
{
    close(m_socket);
}

TcpClientSocket::TcpClientSocket(TcpClientSocket&& a_other)
: m_socket(a_other.m_socket)
{
    a_other.m_socket = -1;
}

TcpClientSocket& TcpClientSocket::operator=(TcpClientSocket && a_other)
{
    if (this != &a_other)
    {
        close(m_socket);
        m_socket = a_other.m_socket;
        a_other.m_socket = -1;
    }
    return *this;
}

bool TcpClientSocket::bind(Adress const& a_adress)
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(a_adress.get_ip());
    sin.sin_port = htons(a_adress.get_port());

    std::cout << "connecting to server\n";

    int is_connected = ::connect(m_socket, (struct sockaddr*)&sin, sizeof(sin));
    if(is_connected   < 0) 
    {
        std::cout << "connect: failed\n";

        close(m_socket);
        return false;
    }
    return true;
}

int TcpClientSocket::create_socket()
{
    int sock = ::socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
	{
		throw "socket not initialized";
	}
	return sock;
}

std::vector<uint8_t> TcpClientSocket::recieve()
{
	std::vector<uint8_t> buffer;
	int expectedDataLen = buffer.size();

	int readBytes = recv(m_socket, buffer.data(), expectedDataLen, 0);

	if(readBytes <= 0)
	{
		throw "no message";
	}
	//call_back(buffer);

	return buffer;
}



void TcpClientSocket::send(std::vector<uint8_t> const& a_buffer)
{
    int sentBytes = ::send(m_socket, a_buffer.data(), a_buffer.size(), 0);

	if(sentBytes < 0)
    {
        throw "send failed";
    } 
	
}


int TcpClientSocket::get_socket()
{
    return m_socket; 
}



} //net