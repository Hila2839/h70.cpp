#include <string>

#include "JmpInstruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class JG: public JmpInstruction
{
public:
    virtual bool is_to_adress(int a_first, int a_second);
    static const std::string NAME;
};

Instruction* create_jg();

