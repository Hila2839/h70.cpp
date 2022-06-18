#include <string>
#include <cstdio>

#include "Dup.hpp"



const std::string DUP::NAME = "DUP";


DUP::DUP(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_dup(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new DUP(a_ip, a_stack);
}


 void DUP::execute()
 {
    int top = m_stack.pop();
    m_stack.push(top * 2);
    m_ip.next();

 }