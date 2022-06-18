#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class HLT: public Instruction
{
public:
    HLT();
    void execute();
    static const std::string NAME;
private:
    int m_operand;
};

Instruction* create_hlt(Ip& a_ip, Memory& a_memory, Stack& a_stack);

