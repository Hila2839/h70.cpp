#ifndef NUM_H
#define NUM_H


#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class NUM: public Instruction
{
public:
    NUM(Ip& a_ip, Stack& a_stack, std::string a_num);
    void execute();
private:
    Ip& m_ip;
    Stack& m_stack;
    std::string m_operand;
};

Instruction* create_num(Ip& a_ip, Stack& a_stack, std::string a_num);

#endif