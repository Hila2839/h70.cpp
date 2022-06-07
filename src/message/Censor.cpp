#include <string>
#include <cstring>

#include "Censor.hpp"
#include "TextTransformer.hpp"

Censor::Censor(std::string a_string)
: TextTransformer()
, m_string(a_string)
{
}

std::string Censor::incoding()
{
    for(size_t i = 0; i < m_string.size(); ++i)
    {
        std::string word;
        while(m_string[i] != ' ')
        {
            word.push_back(m_string[i]);
        }
        if(word == "idiot" || word == "crazy" || word == "fool" )
        {
            for(size_t j = i - 1;j < word.size(); --j)
            {
                m_string[j] = '*';
            }
        }
    }  
    return m_string;  
}