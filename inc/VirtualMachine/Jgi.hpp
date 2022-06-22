#include <string>

#include "AddrInstruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class JGI: public AddrInstruction
{
public:
    virtual bool is_to_adress(int a_first, int a_second);
    static const std::string NAME;
};

Instruction* create_jgi();

