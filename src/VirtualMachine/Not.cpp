#include <string>

#include "Not.hpp"



const std::string NOT::NAME = "NOT";


NOT::NOT(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_not(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new NOT(a_ip, a_stack);
}


 void NOT::execute()
 {
    if(m_stack.get_size() < 2)
    {
         //throw underflow
    }
    int a = m_stack.pop();
    m_stack.push(!a);
    m_ip.next();
 }