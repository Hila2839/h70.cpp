#include <string>
#include <cstdio>

#include "Je.hpp"



const std::string JE::NAME = "JE";



Instruction* create_je()
{
    return new JE();
}


bool JE::is_to_adress(int a_first, int a_second)
{
    if ( a_first == a_second)
    {
        return true;
    }
    return false;
}