#include <string>
#include <cstdio>

#include "Drop.hpp"



const std::string DROP::NAME = "DROP";


Instruction* create_drop()
{
    return new DROP();
}


 void DROP::execute(Bus& a_bus)
 {
    a_bus.pop_from_stack();
    
   a_bus.ip_next();
 }