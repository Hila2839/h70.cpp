
#ifndef TCPCLIENTSOCKET_HPP
#define TCPCLIENTSOCKET_HPP


#include <string>
#include <vector>

namespace net{


class TcpClientSocket
{
public:
    TcpClientSocket();
    TcpClientSocket(int a_socket);
    ~TcpClientSocket();

    TcpClientSocket(TcpClientSocket&& a_other);

    TcpClientSocket& operator=(TcpClientSocket && a_other);

    int create_socket();

    TcpClientSocket accept();

    std::vector<uint8_t> recieve();
    void send(std::vector<uint8_t> const& a_buffer);
    bool bind(const char* a_ip, int a_port);

    //int get_socket();   
private:
    TcpClientSocket& operator=(TcpClientSocket const& a_other) = delete;
    TcpClientSocket(TcpClientSocket const& a_other) = delete;

private:
    friend class TcpSelector;
    friend class TcpServer;

    int get_socket();        



private:
    int m_socket;
};

} //namespace net

#endif // TCPCLIENTSOCKET_HPP


