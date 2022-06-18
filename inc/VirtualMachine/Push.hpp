#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class PUSH: public Instruction
{
public:
    PUSH(Ip& a_ip, Stack& a_stack);
    static const std::string NAME;
private:
    Ip& m_ip;
    Stack& m_stack;
    int m_operand;
};


