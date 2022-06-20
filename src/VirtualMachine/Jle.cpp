#include <string>
#include <cstdio>

#include "Jle.hpp"



const std::string JLE::NAME = "JLE";



Instruction* create_jle()
{
    return new JLE();
}


bool JLE::is_to_adress(int a_first, int a_second)
{
    if ( a_first <= a_second)
    {
        return true;
    }
    return false;
}