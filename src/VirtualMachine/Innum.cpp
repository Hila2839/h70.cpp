#include <string>
#include <cstdio>

#include "Innum.hpp"



const std::string INNUM::NAME = "INNUM";


INNUM::INNUM(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_innum(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new INNUM(a_ip, a_stack);
}


 void INNUM::execute()
 {
     std::cout<<"enter a number\n";
    int c;
    std::cin >> c;
    if(c )//???
    {
         //throw not valid
    }
    m_stack.push(c);
    m_ip.next();
 }