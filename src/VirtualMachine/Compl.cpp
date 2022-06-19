#include <string>

#include "Compl.hpp"



const std::string COMPL::NAME = "COMPL";


Instruction* create_compl()
{
    return new COMPL();
}




 void COMPL::execute(Bus& a_bus)
 {
    
    int a = a_bus.pop_from_stack();
    
    a_bus.push_to_stack(~a);
    a_bus.ip_next();
 }