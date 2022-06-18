#include <string>

#include "Num.hpp"



NUM::NUM(Ip& a_ip, Stack& a_stack, std::string a_num)
: m_ip(a_ip)
, m_stack(a_stack)
, m_operand(a_num)
{
}


Instruction* create_num(Ip& a_ip, Stack& a_stack, std::string a_num)
{
    return new NUM(a_ip, a_stack, a_num);
}


 void NUM::execute()
 {
    int num;
    num = atoi(m_operand.c_str());
    m_stack.push(num);
    m_ip.next();
 }