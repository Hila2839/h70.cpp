#ifndef TCPSELECTOR_HPP
#define TCPSELECTOR_HPP

#include "tcp_server.hpp"

namespace net{

class TcpSelector
{
public:
    void select(TcpServer& a_server);
private:
    //TcpServer& m_server;
};






}//namespace net

#endif