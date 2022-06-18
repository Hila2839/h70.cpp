#include <string>
#include <cstdio>

#include "Load.hpp"



const std::string LOAD::NAME = "LOAD";


LOAD::LOAD(Ip& a_ip, Stack& a_stack, Memory& a_memory)
: m_ip(a_ip)
, m_stack(a_stack)
, m_memory(a_memory)
{
}


Instruction* create_load(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new LOAD(a_ip, a_stack, a_memory);
}


 void LOAD::execute()
 {
    int adress = m_stack.pop();
    int data = m_memory.get_data(adress);
    m_stack.push(data);
    m_ip.next();
 }