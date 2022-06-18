#include <string>

#include "Add.hpp"



const std::string ADD::NAME = "ADD";


ADD::ADD(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_add(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new ADD(a_ip, a_stack);
}


 void ADD::execute()
 {
    if(m_stack.get_size() < 2)
    {
         //throw underflow
    }
    int a = m_stack.pop();
    int b = m_stack.pop();
    m_stack.push(a + b);
    m_ip.next();
 }