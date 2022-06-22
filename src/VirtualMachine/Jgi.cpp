#include <string>
#include <cstdio>

#include "Jgi.hpp"



const std::string JGI::NAME = "JGI";



Instruction* create_jgi()
{
    return new JGI();
}


bool JGI::is_to_adress(int a_first, int a_second)
{
    if ( a_first > a_second)
    {
        return true;
    }
    return false;
}