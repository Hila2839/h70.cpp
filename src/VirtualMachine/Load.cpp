#include <string>
#include <cstdio>

#include "Load.hpp"



const std::string LOAD::NAME = "LOAD";


Instruction* create_load()
{
    return new LOAD();
}


 void LOAD::execute(Bus& a_bus)
 {
    int adress = a_bus.pop_from_stack();
    int data = a_bus.get_data(adress);
    a_bus.push_to_stack(data);
     a_bus.ip_next();
 }