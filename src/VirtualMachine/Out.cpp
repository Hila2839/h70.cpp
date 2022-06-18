#include <string>
#include <cstdio>

#include "Out.hpp"



const std::string OUT::NAME = "OUT";


OUT::OUT(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_out(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new OUT(a_ip, a_stack);
}


 void OUT::execute()
 {
    if(m_stack.get_size() < 1)
    {
         //throw underflow
    }
    char a = m_stack.pop();
    std::cout<<a<<'\n';
    m_ip.next();
 }