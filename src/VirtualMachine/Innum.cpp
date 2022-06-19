#include <string>
#include <cstdio>

#include "Innum.hpp"



const std::string INNUM::NAME = "INNUM";


Instruction* create_innum()
{
    return new INNUM();
}


 void INNUM::execute(Bus& a_bus)
 {
     std::cout<<"enter a number\n";
    int c;
    std::cin >> c;
    
    a_bus.push_to_stack(c);
    a_bus.ip_next();
 }