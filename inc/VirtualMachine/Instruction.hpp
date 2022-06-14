#ifndef INSTRUCTION_H
#define INSTRUCTION_H


class Instruction
{
public:
    Instruction();
    Instruction(int a_num);
    virtual ~Instruction();
    virtual void execute() = 0;

private:
    int m_operand;//? virtual?
};







#endif