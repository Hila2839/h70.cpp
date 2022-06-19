#include <string>
#include <cstdio>
#include <stdlib.h>

#include "Hlt.hpp"



const std::string HLT::NAME = "HLT";



Instruction* create_hlt()
{
    return new HLT();
}



 void HLT::execute(Bus& a_bus)
 {
     exit(0);
 }