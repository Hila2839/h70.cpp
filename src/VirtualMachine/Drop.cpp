#include <string>
#include <cstdio>

#include "Drop.hpp"



const std::string DROP::NAME = "DROP";


DROP::DROP(Ip& a_ip, Stack& a_stack)
: m_ip(a_ip)
, m_stack(a_stack)
{
}


Instruction* create_drop(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new DROP(a_ip, a_stack);
}


 void DROP::execute()
 {
    if(m_stack.get_size() < 1)
    {
         //throw underflow
    }
    m_stack.pop();
    
    m_ip.next();
 }