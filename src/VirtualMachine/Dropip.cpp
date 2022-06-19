#include <string>
#include <cstdio>

#include "Dropip.hpp"



const std::string DROPIP::NAME = "DROPIP";


Instruction* create_dropip()
{
    return new DROPIP();
}


 void DROPIP::execute(Bus& a_bus)
 {
    a_bus.pop_from_ip_stack();
    a_bus.ip_next();
 }