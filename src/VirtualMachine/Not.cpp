#include <string>

#include "Not.hpp"



const std::string NOT::NAME = "NOT";



Instruction* create_not()
{
    return new NOT();
}


 void NOT::execute(Bus& a_bus)
 {
    int a = a_bus.pop_from_stack();
    a_bus.push_to_stack(!a);
    a_bus.ip_next();
 }

