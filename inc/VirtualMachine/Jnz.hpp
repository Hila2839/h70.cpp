#include <string>

#include "IpInstruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class JNZ: public IpInstruction
{
public:
    virtual bool is_to_adress(int a_is_zero);
    static const std::string NAME;
};

Instruction* create_jnz();

