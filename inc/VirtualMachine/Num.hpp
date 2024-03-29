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
    NUM(std::string a_num);
    void execute(Bus& a_bus);
private:
    std::string m_operand;
};

Instruction* create_num(std::string a_num);

#endif