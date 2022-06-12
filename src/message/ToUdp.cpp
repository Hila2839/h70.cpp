#include <sys/socket.h>
#include <unistd.h>
#include <cassert>
#include <cstring> /*memset*/
#include <stdlib.h>/*printf*/
#include <netinet/in.h>
#include <iostream>

#include "ToUdp.hpp"

ToUdp::ToUdp(char* a_adress, char* a_port)
: m_sockaddr()
, m_socket(socket(AF_INET, SOCK_DGRAM, 0))
{
    assert(m_socket>0 && "soket failed");

    memset(&m_sockaddr, 0, sizeof(m_sockaddr));

    m_sockaddr.sin_family = AF_INET;
    m_sockaddr.sin_addr.s_addr = inet_addr(a_adress);
    m_sockaddr.sin_port = htons(atoi(a_port));

}



~ToUdp::ToUdp()
{
    close(m_socket);
}


void ToUdp::send(std::string const& a_text)
{
    char* cstr = new char[a_text.length() + 1];
    strcpy(cstr, a_text.c_str());

    int sendBytes = sendto(m_socket, cstr, a_text.length(), 0, 
        (struct sockaddr *) &m_sockaddr, sizeof(m_sockaddr));

    assert(sendBytes >= 0 && "sending failed");

    std::cout<<"message sent\n";
}

