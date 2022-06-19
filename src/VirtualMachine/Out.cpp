#include <string>
#include <cstdio>

#include "Out.hpp"



const std::string OUT::NAME = "OUT";


Instruction* create_out()
{
    return new OUT();
}




 void OUT::execute(Bus& a_bus)
 {
    char a = a_bus.pop_from_stack();
    std::cout<<a<<'\n';
   a_bus.ip_next();
 }