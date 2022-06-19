#include <string>
#include <cstdio>

#include "Dup.hpp"



const std::string DUP::NAME = "DUP";


Instruction* create_dup()
{
    return new DUP();
}


 void DUP::execute(Bus& a_bus)
 {
    int top = a_bus.pop_from_stack();
    a_bus.push_to_stack(top * 2);
    a_bus.ip_next();

 }