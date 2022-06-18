#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class LOAD: public Instruction
{
public:
    LOAD(Ip& a_ip, Stack& a_stack, Memory& a_memory);
    void execute();
    static const std::string NAME;
private:
    Ip& m_ip;
    Stack& m_stack;
    Memory& m_memory;
    int m_operand;
};

Instruction* create_load(Ip& a_ip, Memory& a_memory, Stack& a_stack);

