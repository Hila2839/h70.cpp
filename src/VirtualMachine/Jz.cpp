#include <string>
#include <cstdio>

#include "Jz.hpp"



const std::string JZ::NAME = "JZ";


Instruction* create_jz()
{
    return new JZ();
}

bool JZ::is_to_adress(int a_is_zero)
{
    if (a_is_zero == 0)
    {
        return true;
    }
    return false;
}
