#ifndef SERVER_HANDLER_NUM_HPP
#define SERVER_HANDLER_NUM_HPP

#include <string>

#include "handler.hpp"

namespace net{


class ServerHandlerNum: public Handler
{
public:
    ServerHandlerNum(int a_number);
    std::vector<uint8_t> handle(std::vector<uint8_t> const& a_message, size_t a_read_bytes);

private:
    int m_number;
};


}//namespace net

#endif
