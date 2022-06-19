#include <string>

#include "Num.hpp"



NUM::NUM(std::string a_num)
: m_operand(a_num)
{
}


Instruction* create_num(std::string a_num)
{
    return new NUM( a_num);
}



 void NUM::execute(Bus& a_bus)
 {
    int num;
    num = atoi(m_operand.c_str());
    a_bus.push_to_stack(num);
    a_bus.ip_next();
 }