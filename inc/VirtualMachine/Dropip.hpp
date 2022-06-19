#ifndef DROPIP_H
#define DROPIP_H

#include <string>

#include "Instruction.hpp"



class DROPIP: public Instruction
{
public:
   void execute(Bus& a_bus);
    static const std::string NAME;
};

Instruction* create_dropip();

#endif//DROPIP_H