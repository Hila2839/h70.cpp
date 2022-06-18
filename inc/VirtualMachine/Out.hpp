#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class OUT: public Instruction
{
public:
    OUT(Ip& a_ip, Stack& a_stack);
    void execute();
    static const std::string NAME;
private:
    Ip& m_ip;
    Stack& m_stack;
    int m_operand;
};

Instruction* create_out(Ip& a_ip, Memory& a_memory, Stack& a_stack);

