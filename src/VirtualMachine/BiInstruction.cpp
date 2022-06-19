
#include "BiInstruction.hpp"


void BiInstruction::execute(Bus& a_bus)
{
    int first = a_bus.pop_from_stack();
    int second = a_bus.pop_from_stack();

    a_bus.push_to_stack(actual_op(first, second));

    a_bus.ip_next();

}
