#include <string>
#include <cstring>

#include "LowerCase.hpp"
#include "TextTransformer.hpp"
/*
LowerCase::LowerCase(std::string a_string)
: TextTransformer()
, m_string(a_string)
{
}
*/
std::string LowerCase::m_name = "lower";

std::string const& LowerCase::get_name()
{
    return m_name;
}


std::string LowerCase::incoding(std::string const& a_string)
{
    std::string new_string = a_string;
    for(size_t i = 0; i < a_string.size(); ++i)
    {
        new_string[i] = tolower(a_string[i]);
    }  
    return new_string; 
}
