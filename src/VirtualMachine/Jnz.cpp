#include <string>
#include <cstdio>

#include "Jnz.hpp"



const std::string JNZ::NAME = "JNZ";


JNZ::JNZ(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_jnz(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new JNZ(a_ip, a_stack);
}


 void JNZ::execute()
 {
    int is_zero = m_stack.pop();
    int adress = m_stack.pop();
    if(is_zero != 0)
    {
        m_ip.jump_to(adress);
    }
    else
    {
        m_ip.next();
    }
 }