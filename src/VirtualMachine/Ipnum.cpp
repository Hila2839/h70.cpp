#include <string>

#include "Ipnum.hpp"



IPNUM::IPNUM(std::string a_num)
: m_operand(a_num)
{
}


Instruction* create_ipnum(std::string a_num)
{
    return new IPNUM( a_num);
}



 void IPNUM::execute(Bus& a_bus)
 {
    int num;
    num = atoi(m_operand.c_str());
    a_bus.push_to_ip_stack(num);
    a_bus.ip_next();
 }