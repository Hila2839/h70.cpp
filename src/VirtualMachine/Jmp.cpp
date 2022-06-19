#include <string>
#include <cstdio>

#include "Jmp.hpp"



const std::string JMP::NAME = "JMP";



Instruction* create_jmp()
{
    return new JMP();
}


bool JMP::is_to_adress(int a_is_zero)
{
        return true;
}