
#include "server_handler_num.hpp"

namespace net{

ServerHandlerNum::ServerHandlerNum(uint8_t a_number)
: m_number(a_number)
{
}


std::vector<uint8_t> ServerHandlerNum::handle(std::vector<uint8_t> const& a_message,
    size_t a_read_bytes)
{
    std::vector<uint8_t> answer;

    //uint8_t number = static_cast<uint8_t> (m_number);

    // if(a_read_bytes != 1)
    // {
    //     return a_message;
    // }

    if(a_message[0] < m_number)
    {
        answer.push_back('<');
    }  

    if(a_message[0] > m_number) 
    {
        answer.push_back('>');
    }   

    if(a_message[0] == m_number) 
    {
        answer.push_back('=');
        break;
    }        
    return answer;  

}

}
