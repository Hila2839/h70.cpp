#include <string>
#include <cstdio>

#include "Rol3.hpp"



const std::string ROL3::NAME = "ROL3";


Instruction* create_rol3()
{
    return new ROL3();
}


 void ROL3::execute(Bus& a_bus)
 {
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    int top_3 = a_bus.pop_from_stack();

    a_bus.push_to_stack(top_1);
    a_bus.push_to_stack(top_3);
    a_bus.push_to_stack(top_2);

    a_bus.ip_next();

 }