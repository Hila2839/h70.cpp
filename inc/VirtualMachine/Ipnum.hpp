#ifndef IPNUM_H
#define IPNUM_H


#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class IPNUM: public Instruction
{
public:
    IPNUM(std::string a_num);
    void execute(Bus& a_bus);
private:
    std::string m_operand;
};

Instruction* create_ipnum(std::string a_num);

#endif