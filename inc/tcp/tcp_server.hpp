#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <list>
#include <memory>

#include "tcp_server_socket.hpp"
#include "tcp_client_socket.hpp"
//#include "tcp_selector.hpp"
#include "selector_interface.hpp"
#include "adress.hpp"
#include "handler.hpp"

class TcpSelector;

namespace net{
    

class TcpServer
{
public:
    TcpServer(Adress const& a_adress, Handler* a_handler);
    ~TcpServer();

    std::string recieve(int a_socket);
    void send(int a_clientSocket, std::vector<uint8_t> const&  a_data);
    
    void run(Selector* a_selector);

    std::list<TcpClientSocket*> get_clients();

    void call_back(std::vector<uint8_t> const&  a_message, int a_client_socket);


   
private:
    friend class TcpSelector;
    int add_new_client();
    void remove_client(std::list<TcpClientSocket*>::iterator a_it);
    bool check_exsist_client(int a_client_socket);
    int get_socket();


private:
    TcpServerSocket m_socket;
    std::list<TcpClientSocket*> m_clients;
    Handler* m_handler;
};

} //namespace net

#endif //TCPSERVER_HPP