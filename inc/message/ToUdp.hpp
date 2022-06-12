#ifndef TOUDP_H
#define TOUDP_H

#include <string>
#include <arpa/inet.h>

#include "TextOutput.hpp"

class ToUdp :public TextOutput{
public:
    ToUdp(char* a_adress, char* a_port);
    ~ToUdp();
    void send(std::string const& a_text);

private:
    struct sockaddr_in m_sockaddr;
    int m_socket;

}




#endif