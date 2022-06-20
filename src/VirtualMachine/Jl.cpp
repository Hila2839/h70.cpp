#include <string>
#include <cstdio>

#include "Jl.hpp"



const std::string JL::NAME = "JL";



Instruction* create_jl()
{
    return new JL();
}


bool JL::is_to_adress(int a_first, int a_second)
{
    if ( a_first < a_second)
    {
        return true;
    }
    return false;
}