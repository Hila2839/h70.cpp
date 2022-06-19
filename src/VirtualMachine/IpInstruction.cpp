
#include "IpInstruction.hpp"


void IpInstruction::execute(Bus& a_bus)
{
    int is_zero = a_bus.pop_from_stack();
    int adress = a_bus.pop_from_stack();

    if(is_to_adress(is_zero))
    {
        a_bus.move_ip_to(adress);
    }
    a_bus.ip_next();

}
