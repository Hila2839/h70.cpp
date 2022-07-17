
#ifndef TCPCLIENTSOCKET_HPP
#define TCPCLIENTSOCKET_HPP


#include <string>
#include <vector>

#include "adress.hpp"

namespace net{


class TcpClientSocket
{
public:
    TcpClientSocket();
    ~TcpClientSocket();

    TcpClientSocket(TcpClientSocket&& a_other);

    TcpClientSocket& operator=(TcpClientSocket && a_other);

    int create_socket();

    TcpClientSocket accept();

    std::vector<uint8_t> recieve();
    void send(std::vector<uint8_t> const& a_buffer);
    //void send(std::string const& a_text);
    bool bind(Adress const& a_adress);

    
private:
    friend class TcpServerSocket;
    TcpClientSocket(int a_socket);

private:
    TcpClientSocket& operator=(TcpClientSocket const& a_other) = delete;
    TcpClientSocket(TcpClientSocket const& a_other) = delete;

private:
    friend class TcpSelector;
    friend class TcpServer;
    friend class Work;
    friend class Processor;

    int get_socket();        

private:
    int m_socket;
};

} //namespace net

#endif // TCPCLIENTSOCKET_HPP


