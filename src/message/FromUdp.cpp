#include <sys/socket.h>
#include <unistd.h>
#include <cassert>
#include <cstring> /*memset*/
#include <stdlib.h>/*printf*/
#include <netinet/in.h>
#include <iostream>

#include "FromUdp.hpp"

FromUdp::FromUdp(char* a_adress, char* a_port)
: m_sockaddr()
, m_socket(socket(AF_INET, SOCK_DGRAM, 0))
{
    assert(m_socket>0 && "soket failed");

    memset(&m_sockaddr, 0, sizeof(m_sockaddr));

    m_sockaddr.sin_family = AF_INET;
    m_sockaddr.sin_addr.s_addr = inet_addr(a_adress);
    m_sockaddr.sin_port = htons(atoi(a_port));


    int result = bind(m_socket, (struct sockaddr *) (&m_sockaddr), sizeof(m_sockaddr));
    assert(result > -1 && "connect socket failed");
}



~FromUdp::FromUdp()
{
    close(m_socket);
}


std::string FromUdp::recieve()
{
    unsigned int sinLen = sizeof(m_sockaddr);
    int readBytes = 0;
    char buffer[4096];
    
    std::string data;

    std::cout<<"recievig....\n";

    readBytes = recvfrom(m_socket, buffer, sizeof(buffer), 0, 
        (struct sockaddr *) &m_sockaddr, &sinLen);

    data += buffer;
    
    if(data == "EOM")
    {
        data = '';
        return data;
    }

    while(true)
    {
        std::cout<<"recievig....\n";

    readBytes = recvfrom(m_socket, buffer, sizeof(buffer), 0, 
        (struct sockaddr *) &m_sockaddr, &sinLen);

        assert(readBytes >= 0 && "recieving failed");

        if(buffer[0] == 'E' && buffer[1] == 'O' && buffer[2] == 'M')
        {
            break;
        }
        data += '\n';
        data += buffer;
    }
    buffer += '\0';
    return data;
}
    
