#include <string>
#include <cstdio>
#include <stdlib.h>

#include "Hlt.hpp"



const std::string HLT::NAME = "HLT";


HLT::HLT()
{
}


Instruction* create_hlt(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    return new HLT();
}


 void HLT::execute()
 {
     exit(0);
 }