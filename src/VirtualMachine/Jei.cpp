#include <string>
#include <cstdio>

#include "Jei.hpp"



const std::string JEI::NAME = "JEI";



Instruction* create_jei()
{
    return new JEI();
}


bool JEI::is_to_adress(int a_first, int a_second)
{
    if ( a_first == a_second)
    {
        return true;
    }
    return false;
}