#include "server_handler_push.hpp"
#include "work.hpp"
#include "../../inc/queue/safe_q.hpp"

namespace net{


ServerHandlerPush::ServerHandlerPush(SafeQueue<Work, 1000>& a_queue)
: m_queue(a_queue)
{
}


void ServerHandlerPush::handle(std::vector<uint8_t> const& a_message, size_t a_read_bytes, TcpClientSocket* a_client_socket)
{
    m_queue.enqueue(Work(a_client_socket, a_message));
    std::cout<<"in queue:"<<m_queue.size()<<'\n';
}



}//namespace net


