#include <string>
#include <cstdio>

#include "Jmp.hpp"



const std::string JMP::NAME = "JMP";


JMP::JMP(Ip& a_ip, Stack& a_stack, Memory& a_memory)
: m_ip(a_ip)
, m_stack(a_stack)
, m_memory(a_memory)
{
}


Instruction* create_jmp(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new JMP(a_ip, a_stack, a_memory);
}


 void JMP::execute()
 {
    int adress = m_stack.pop();

    m_ip.jump_to(adress);
 }