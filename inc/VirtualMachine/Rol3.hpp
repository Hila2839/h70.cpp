#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class ROL3: public Instruction
{
public:
    ROL3(Ip& a_ip, Stack& a_stack);
    void execute();
    static const std::string NAME;
private:
    Ip& m_ip;
    Stack& m_stack;
    int m_operand;
};

Instruction* create_rol3(Ip& a_ip, Memory& a_memory, Stack& a_stack);

