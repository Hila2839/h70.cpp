#ifndef IP_INSTRUCTION_H
#define IP_INSTRUCTION_H

#include "Instruction.hpp"

class IpInstruction : public Instruction
{
public:
    virtual void execute(Bus& a_bus);

private:
    virtual bool is_to_adress(int a_is_zero) = 0;
};








#endif