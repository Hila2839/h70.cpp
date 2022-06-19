#include <string>
#include <cstdio>

#include "Stor.hpp"



const std::string STOR::NAME = "STOR";


Instruction* create_stor()
{
    return new STOR();
}



 void STOR::execute(Bus& a_bus)
 {
    int adress = a_bus.pop_from_stack();
    int data = a_bus.pop_from_stack();
    
    a_bus.set_data(adress, data);

    a_bus.ip_next();
 }