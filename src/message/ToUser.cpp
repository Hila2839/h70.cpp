#include <cstring>
#include <iostream>

#include "ToUser.hpp"
#include "TextOutput.hpp"


ToUser::ToUser(std::string a_string)
: TextOutput()
, m_string(a_string)
{
}

void ToUser::output()
{
    for (size_t i = 0; i < m_string.size(); i++)
    {
       std::cout<< m_string[i];
    }
}

