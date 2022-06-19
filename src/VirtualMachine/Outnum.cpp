#include <string>
#include <cstdio>

#include "Outnum.hpp"



const std::string OUTNUM::NAME = "OUTNUM";



Instruction* create_outnum()
{
    return new OUTNUM();
}




 void OUTNUM::execute(Bus& a_bus)
 {
    int a = a_bus.pop_from_stack();
    std::cout<<a<<'\n';
    a_bus.ip_next();
 }