#include <string>
#include <cstdio>

#include "Jnz.hpp"



const std::string JNZ::NAME = "JNZ";



Instruction* create_jnz()
{
    return new JNZ();
}


bool JNZ::is_to_adress(int a_is_zero)
{
    if (a_is_zero != 0)
    {
        return true;
    }
    return false;
}