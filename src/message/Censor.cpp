#include <string>
#include <cstring>

#include "Censor.hpp"
#include "TextTransformer.hpp"
/*
Censor::Censor(std::string a_string)
: TextTransformer()
, m_string(a_string)
{
}
*/
std::string Censor::incoding(std::string a_string)
{
    std::string new_string = a_string;
    
    std::size_t found =  new_string.find("idiot");
    if(found != std::string::npos)
    {
        for(size_t j = found;j < found + 5; ++j)
            {
                new_string[j] = '*';
            }
    }
    std::size_t found_1 =  new_string.find("crazy");
    if(found_1 != std::string::npos)
    {
        for(size_t j = found_1;j < found + 5; ++j)
            {
                new_string[j] = '*';
            }
    }
    std::size_t found_2 =  new_string.find("fool");
    if(found_2 != std::string::npos)
    {
        for(size_t j = found_2;j < found + 4; ++j)
            {
                new_string[j] = '*';
            }
    } 
    return new_string;  
}