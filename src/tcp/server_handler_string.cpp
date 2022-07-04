
#include "server_handler_string.hpp"

std::vector<uint8_t> ServerHandlerString::handle(std::vector<uint8_t> const& a_message,
    size_t a_read_bytes)
{
    std::vector<uint8_t> upper_message;

    for (auto letter: a_message)
    {
        upper_message.push_back(toupper(letter));
    }

    return upper_message;            
}
