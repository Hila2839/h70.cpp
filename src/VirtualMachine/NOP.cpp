#include <string>

#include "NOP.hpp"



const std::string NOP::NAME = "NOP";


NOP::NOP(Ip& a_ip)
: m_ip(a_ip)
{
}





Instruction* create_nop(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new NOP(a_ip);
}




 void NOP::execute()
 {
    m_ip.next();
 }