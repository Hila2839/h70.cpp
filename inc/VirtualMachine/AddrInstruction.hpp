#ifndef ADDRJMP_INSTRUCTION_H
#define ADDRJMP_INSTRUCTION_H

#include "Instruction.hpp"

class AddrInstruction : public Instruction
{
public:
    virtual void execute(Bus& a_bus);

private:
    virtual bool is_to_adress(int a_first, int a_second) = 0;
};








#endif