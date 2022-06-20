#include <string>

#include "AddrNum.hpp"



AddrNUM::AddrNUM(std::string a_num)
: m_operand(a_num)
{
}


Instruction* create_addr_num(std::string a_num)
{
    return new AddrNUM( a_num);
}



 void AddrNUM::execute(Bus& a_bus)
 {
    int num;
    num = atoi(m_operand.c_str());
    a_bus.move_ip_to(num);
 }