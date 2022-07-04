#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <list>
#include <memory>

#include "tcp_server_socket.hpp"
#include "tcp_client_socket.hpp"

namespace net{
    

class TcpServer
{
public:
    TcpServer(const char* a_ip, int a_port);
    ~TcpServer();

    std::string recieve(int a_socket);
    void send(int a_clientSocket, std::vector<uint8_t> const&  a_data);

    void server_run();
    std::list<TcpClientSocket*> get_clients();

    // int get_socket();
    // void remove_client(std::list<TcpClientSocket*>::iterator a_it);
    // bool check_exsist_client(int a_client_socket);
private:
    friend class TcpSelector;
    int add_new_client();
    void remove_client(std::list<TcpClientSocket*>::iterator a_it);
    bool check_exsist_client(int a_client_socket);
    int get_socket();

private:
    TcpServerSocket m_socket;
    std::list<TcpClientSocket*> m_clients;
};

} //namespace net

#endif //TCPSERVER_HPP