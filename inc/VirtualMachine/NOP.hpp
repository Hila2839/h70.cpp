#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class NOP: public Instruction
{
public:
    NOP(Ip& a_ip);
    void execute();
    static const std::string NAME;
private:
    Ip& m_ip;
};

Instruction* create_nop(Ip& a_ip, Memory& a_memory, Stack& a_stack);

