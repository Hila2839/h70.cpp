#ifndef FROMUDP_H
#define FROMUDP_H

#include <string>
#include <arpa/inet.h>

#include "TextInput.hpp"

class FromUdp :public TextInput{
public:
    FromUdp(char* a_adress, char* a_port);
    ~FromUdp();
    std::string recieve();

private:
    struct sockaddr_in m_sockaddr;
    int m_socket;

}




#endif