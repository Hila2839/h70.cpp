#include <string>
#include <cstdio>

#include "Jg.hpp"



const std::string JG::NAME = "JG";



Instruction* create_jg()
{
    return new JG();
}


bool JG::is_to_adress(int a_first, int a_second)
{
    if ( a_first > a_second)
    {
        return true;
    }
    return false;
}