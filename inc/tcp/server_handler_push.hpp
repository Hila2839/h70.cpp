#ifndef SERVER_HANDLER_PUSH_HPP
#define SERVER_HANDLER_PUSH_HPP

#include <string>

#include "handler.hpp"
#include "work.hpp"
#include "../../inc/queue/safe_q.hpp"

namespace net{


class ServerHandlerPush : public Handler
{
public:

    ServerHandlerPush(SafeQueue<Work, 1000>& a_queue);

    void handle(std::vector<uint8_t> const& a_message, size_t a_read_bytes, TcpClientSocket* a_client_socket);

private:
    SafeQueue<Work, 1000>& m_queue;
};


}//namespace net

#endif
