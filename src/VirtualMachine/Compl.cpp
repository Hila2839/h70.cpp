#include <string>

#include "Compl.hpp"



const std::string COMPL::NAME = "COMPL";


COMPL::COMPL(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_compl(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new COMPL(a_ip, a_stack);
}


 void COMPL::execute()
 {
    
    int a = m_stack.pop();
    
    m_stack.push(~a);
    m_ip.next();
 }