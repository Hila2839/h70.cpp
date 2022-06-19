#include <string>

#include "Nop.hpp"



const std::string NOP::NAME = "NOP";


Instruction* create_nop()
{
    return new NOP();
}




 void NOP::execute(Bus& a_bus)
 {
    a_bus.ip_next();
 }