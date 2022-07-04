#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <sys/select.h> /*select*/


#include "tcp_server.hpp"
#include "selector_interface.hpp"



//class TcpServer;

namespace net{

class TcpSelector: public Selector
{
public:
    TcpSelector(TcpServer& a_server);
    void select();
    void is_activate_clients(TcpServer& a_server, fd_set* a_master, fd_set* a_temp, int activity);

private:
    TcpServer& m_server;
};






}//namespace net

#endif