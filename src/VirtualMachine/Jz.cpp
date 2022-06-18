#include <string>
#include <cstdio>

#include "Jz.hpp"



const std::string JZ::NAME = "JZ";


JZ::JZ(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_jz(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new JZ(a_ip, a_stack);
}


 void JZ::execute()
 {
    int is_zero = m_stack.pop();
    int adress = m_stack.pop();
    if(is_zero == 0)
    {
        m_ip.jump_to(adress);
    }
    else
    {
        m_ip.next();
    }
 }