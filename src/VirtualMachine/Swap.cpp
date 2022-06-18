#include <string>
#include <cstdio>

#include "Swap.hpp"



const std::string SWAP::NAME = "SWAP";


SWAP::SWAP(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_swap(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new SWAP(a_ip, a_stack);
}


 void SWAP::execute()
 {
    int top_1 = m_stack.pop();
    int top_2 = m_stack.pop();

    m_stack.push(top_1);
    m_stack.push(top_2);

    m_ip.next();

 }