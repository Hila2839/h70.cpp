#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class NOT: public Instruction
{
public:
    NOT(Ip& a_ip, Stack& a_stack);
    void execute();
    static const std::string NAME;
private:
    Ip& m_ip;
    Stack& m_stack;
    int m_operand;
};

Instruction* create_not(Ip& a_ip, Memory& a_memory, Stack& a_stack);

