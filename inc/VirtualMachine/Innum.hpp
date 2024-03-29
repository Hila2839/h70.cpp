#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class INNUM: public Instruction
{
public:
   void execute(Bus& a_bus);
    static const std::string NAME;
};

Instruction* create_innum();

