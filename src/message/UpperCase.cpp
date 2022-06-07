#include <iostream>
#include <cstring>
#include <string>

#include "UpperCase.hpp"
#include "TextTransformer.hpp"
/*
UpperCase::UpperCase(std::string a_string)
: TextTransformer()
, m_string(a_string)
{
}
*/
std::string UpperCase::incoding(std::string a_string)
{
    std::string new_string = a_string;
    for(size_t i = 0; i < a_string.size(); ++i)
    {
        new_string[i] = toupper(a_string[i]);
    }  
    return new_string; 
}