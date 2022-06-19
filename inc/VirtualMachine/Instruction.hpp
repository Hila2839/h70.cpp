#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Bus.hpp"

class Bus;

class Instruction
{
public:
    Instruction();
    Instruction(int a_num);
    virtual ~Instruction();
    //virtual void execute() = 0;
    virtual void execute(Bus& a_bus) = 0;


private:
    int m_operand;//? virtual?
};







#endif