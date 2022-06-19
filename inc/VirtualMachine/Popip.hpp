#ifndef POPIP_H
#define POPIP_H

#include <string>

#include "Instruction.hpp"



class POPIP: public Instruction
{
public:
   void execute(Bus& a_bus);
    static const std::string NAME;
};

Instruction* create_popip();

#endif//POPIP_H