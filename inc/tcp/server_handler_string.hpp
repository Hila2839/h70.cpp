#ifndef SERVER_HANDLER_STRING_HPP
#define SERVER_HANDLER_STRING_HPP

#include <string>

#include "handler.hpp"

namespace net{


class ServerHandlerString : public Handler
{
public:
    ServerHandlerString();
    std::vector<uint8_t> handle(std::vector<uint8_t> const& a_message, size_t a_read_bytes);

private:
    
};


}//namespace net

#endif
