#ifndef BI_INSTRUCTION_H
#define BI_INSTRUCTION_H

#include "Instruction.hpp"
#include "Bus.hpp"

class BiInstruction : public Instruction
{
public:
    virtual void execute(Bus& a_bus);

private:
    virtual int actual_op(int a_first, int a_second) = 0;
};



#endif