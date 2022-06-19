#include <string>
#include <cstdio>

#include "Popip.hpp"



const std::string POPIP::NAME = "POPIP";


Instruction* create_popip()
{
    return new POPIP();
}


 void POPIP::execute(Bus& a_bus)
 {
    int adress = a_bus.pop_from_ip_stack();
    a_bus.move_ip_to(adress);
 }