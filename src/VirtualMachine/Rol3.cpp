#include <string>
#include <cstdio>

#include "Rol3.hpp"



const std::string ROL3::NAME = "ROL3";


ROL3::ROL3(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_rol3(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new ROL3(a_ip, a_stack);
}


 void ROL3::execute()
 {
    int top_1 = m_stack.pop();
    int top_2 = m_stack.pop();
    int top_3 = m_stack.pop();

    m_stack.push(top_1);
    m_stack.push(top_3);
    m_stack.push(top_2);

    m_ip.next();

 }