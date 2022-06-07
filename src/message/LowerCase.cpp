#include <string>
#include <cstring>

#include "LowerCase.hpp"
#include "TextTransformer.hpp"

LowerCase::LowerCase(std::string a_string)
: TextTransformer()
, m_string(a_string)
{
}

std::string  LowerCase::incoding()
{
    for(size_t i = 0; i < m_string.size(); ++i)
    {
        m_string[i] = tolower(m_string[i]);
    }   
    return m_string; 
}