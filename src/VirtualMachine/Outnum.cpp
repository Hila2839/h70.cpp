#include <string>
#include <cstdio>

#include "Outnum.hpp"



const std::string OUTNUM::NAME = "OUTNUM";


OUTNUM::OUTNUM(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_outnum(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new OUTNUM(a_ip, a_stack);
}


 void OUTNUM::execute()
 {
    if(m_stack.get_size() < 1)
    {
         //throw underflow
    }
    int a = m_stack.pop();
    std::cout<<a<<'\n';
    m_ip.next();
 }