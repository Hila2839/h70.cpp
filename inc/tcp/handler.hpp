#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <stdint.h>
#include <vector>

#include "tcp_client_socket.hpp"

namespace net{


class Handler
{
public:
    virtual ~Handler();

    virtual void handle(std::vector<uint8_t> const& a_message, size_t a_read_bytes, TcpClientSocket* a_client_socket) = 0;
    //virtual bool send_feedback(TcpClientSocket* a_client_socket) = 0;
private:

};


}//namespace net


#endif