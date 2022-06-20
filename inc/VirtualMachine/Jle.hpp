#include <string>

#include "JmpInstruction.hpp"



class JLE: public JmpInstruction
{
public:
    virtual bool is_to_adress(int a_first, int a_second);
    static const std::string NAME;
};

Instruction* create_jle();

