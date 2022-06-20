#ifndef JMP_INSTRUCTION_H
#define JMP_INSTRUCTION_H

#include "Instruction.hpp"

class JmpInstruction : public Instruction
{
public:
    virtual void execute(Bus& a_bus);

private:
    virtual bool is_to_adress(int a_first, int a_second) = 0;
};








#endif