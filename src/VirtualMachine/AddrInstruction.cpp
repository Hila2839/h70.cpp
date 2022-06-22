
#include "AddrInstruction.hpp"


void AddrInstruction::execute(Bus& a_bus)
{
    int first = a_bus.pop_from_stack();
    int second = a_bus.pop_from_stack();

    if(is_to_adress(first, second))
    {
        int adress = a_bus.pop_from_ip_stack();
        a_bus.move_ip_to(adress);
    }
    else
    {
        a_bus.pop_from_ip_stack();
        a_bus.ip_next();
    }
    
}
