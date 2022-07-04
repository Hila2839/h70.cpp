#ifndef TCPSERVERSOCKET_HPP
#define TCPSERVERSOCKET_HPP

#include "tcp_client_socket.hpp"


namespace net{


class TcpServerSocket
{
public:
    TcpServerSocket();
    TcpServerSocket(int a_socket);
    //TcpServerSocket(const char* a_ip, int a_port);
    ~TcpServerSocket();

    TcpServerSocket(TcpServerSocket&& a_other);

    TcpServerSocket& operator=(TcpServerSocket && a_other);

    int create_socket();

    TcpClientSocket* accept();


    void bind(const char* a_ip, int a_port);
    void listen();

private:

    TcpServerSocket& operator=(TcpServerSocket const& a_other) = delete;
    TcpServerSocket(TcpServerSocket const& a_other) = delete;
private:
    friend class TcpSelector;
    friend class TcpServer;

    int get_socket();
private:
    int m_socket;
};

} //namespace net

#endif // TCPSERVERSOCKET_HPP
