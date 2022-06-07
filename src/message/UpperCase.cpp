#include <iostream>
#include <cstring>
#include <string>

#include "UpperCase.hpp"
#include "TextTransformer.hpp"

UpperCase::UpperCase(std::string a_string)
: TextTransformer()
, m_string(a_string)
{
}

std::string UpperCase::incoding()
{
    for(size_t i = 0; i < m_string.size(); ++i)
    {
        m_string[i] = toupper(m_string[i]);
    }  
    return m_string; 
}