#ifndef ADDRNUM_H
#define ADDRNUM_H


#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class AddrNUM: public Instruction
{
public:
    AddrNUM(std::string a_num);
    void execute(Bus& a_bus);
private:
    std::string m_operand;
};

Instruction* create_addrnum(std::string a_num);

#endif