#include <string>
#include <cstdio>

#include "In.hpp"



const std::string IN::NAME = "IN";

Instruction* create_in()
{
    return new IN();
}


 void IN::execute(Bus& a_bus)
 {
    std::cout<<"enter a letter\n";
    int c = getchar();
    
    a_bus.push_to_stack(c);
    a_bus.ip_next();
 }