#include <string>

#include "Label.hpp"



LABEL::LABEL(int a_number)
: m_label_num(a_number)
{
}


Instruction* create_label(int a_number)
{
    return new LABEL(a_number);
}



 void LABEL::execute(Bus& a_bus)
 {
    a_bus.push_to_ip_stack(m_label_num);
    a_bus.ip_next();
 }

 std::string LABEL::get_label()
 {
     return m_operand;
 }


void LABEL::set_label_number(int a_number)
{
    m_label_num = a_number;
}
