#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h>  /*htons*/
#include <unistd.h>     /*close*/
#include <fcntl.h>      /*fcntl*/
#include <sys/select.h> /*select*/
#include <string>
#include <iostream>
#include <cstring>


    
    #include "tcp_server_socket.hpp"
    
    namespace net{


    TcpServerSocket::TcpServerSocket()
    : m_socket(create_socket())
    {
    }

    TcpServerSocket::TcpServerSocket(int a_socket)
    : m_socket(a_socket)
    {
    }

    //TcpServerSocket::TcpServerSocket(const char* a_ip, int a_port);
    


int TcpServerSocket::create_socket()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
	{
		throw "socket not initialized";
	}
	return sock;
}


    TcpServerSocket::~TcpServerSocket()
    {
        if (m_socket >= 0)
        {
            close(m_socket);
        }
    }

    TcpServerSocket::TcpServerSocket(TcpServerSocket&& a_other)
    : m_socket(a_other.m_socket)
    {
        a_other.m_socket = -1;
    }

    TcpServerSocket& TcpServerSocket::operator=(TcpServerSocket && a_other)
    {
        if (this != &a_other)
        {
            close(m_socket);
            m_socket = a_other.m_socket;
            a_other.m_socket = -1;
        }
    return *this;
    }


    



    void TcpServerSocket::bind(const char* a_ip, int a_port)
    {
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
	    sin.sin_addr.s_addr = inet_addr(a_ip);
	    sin.sin_port = htons(a_port);

        int optVal = 1;//??
        //??
	    int set = setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal));
	    if(set < 0)
        {
            throw "set sock failed";
        } 

        int is_bind = ::bind(m_socket, (struct sockaddr*)&sin, sizeof(sin));
        if(is_bind  < 0) 
        {
            throw "binding failed";
        }
    }

void TcpServerSocket::listen()
{
	int is_listen = ::listen(m_socket, 5);
    if(is_listen < 0)
    {
        throw "listen failed";
    }
}

TcpClientSocket* TcpServerSocket::accept()
{
	struct sockaddr client_sin;
	socklen_t sin_len = sizeof(client_sin);

	int clientSocket = ::accept(m_socket, &client_sin, &sin_len);
    if(clientSocket < 0)
    {
        throw "acception failed";
    } 
    
    return new TcpClientSocket(clientSocket);
}


int TcpServerSocket::get_socket()
{
    return m_socket;
}

} //namespace net