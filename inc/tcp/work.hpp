#ifndef WORK_HPP
#define WORK_HPP

#include <vector>
#include <cstdint>
#include "tcp_client_socket.hpp"


struct Work
{
    net::TcpClientSocket* m_client_socket_p;
    std::vector<uint8_t> m_message;
};




#endif //WORK_HPP