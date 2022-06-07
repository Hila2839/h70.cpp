#include <cstring>
#include <iostream>

#include "ToUser.hpp"
#include "TextOutput.hpp"

/*
ToUser::ToUser(std::string a_string)
: TextOutput()
, m_string(a_string)
{
}
*/
void ToUser::output(std::string a_string)
{
    for (size_t i = 0; i < a_string.size(); i++)
    {
       std::cout<< a_string[i];
    }
}

