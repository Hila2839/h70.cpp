#include <string>
#include <cstdio>

#include "In.hpp"



const std::string IN::NAME = "IN";


IN::IN(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_in(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new IN(a_ip, a_stack);
}


 void IN::execute()
 {
     std::cout<<"enter a letter\n";
    int c = getchar();
    if(c < 41)//???
    {
         //throw not valid
    }
    m_stack.push(c);
    m_ip.next();
 }