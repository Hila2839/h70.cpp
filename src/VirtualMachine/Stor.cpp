#include <string>
#include <cstdio>

#include "Stor.hpp"



const std::string STOR::NAME = "STOR";


STOR::STOR(Ip& a_ip, Stack& a_stack, Memory& a_memory)
: m_ip(a_ip)
, m_stack(a_stack)
, m_memory(a_memory)
{
}


Instruction* create_stor(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new STOR(a_ip, a_stack, a_memory);
}


 void STOR::execute()
 {
    int adress = m_stack.pop();
    int data = m_stack.pop();
    
    m_memory.set_data(adress, data);

    m_ip.next();
 }