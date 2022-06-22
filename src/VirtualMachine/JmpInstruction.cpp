
#include "JmpInstruction.hpp"


void JmpInstruction::execute(Bus& a_bus)
{
    int first = a_bus.pop_from_stack();
    int second = a_bus.pop_from_stack();

    if(is_to_adress(first, second))
    {
        a_bus.ip_next();
        a_bus.get_Instruction(a_bus.get_ip())->execute(a_bus);
        a_bus.ip_next();

    }
    else
    {
        a_bus.ip_next();
        a_bus.ip_next();
    }

}
