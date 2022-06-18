#include <string>

#include "Push.hpp"



const std::string PUSH::NAME = "PUSH";


PUSH::PUSH(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


