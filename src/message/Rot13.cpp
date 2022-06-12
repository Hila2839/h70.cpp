#include <string>
#include <cstring>

#include "Rot13.hpp"
#include "TextTransformer.hpp"

std::string Rot13::m_name = "rot13";


std::string const& Rot13::get_name()
{
    
    return m_name;
}


std::string Rot13::incoding(std::string const& a_string)
{
std::string trans_string = a_string;
for(size_t i = 0; i <= trans_string.size(); ++i)
{
    if(isupper(trans_string[i]) && (trans_string[i] + 13 <= 90))
    {
        trans_string[i] = trans_string[i] + 13;
    }
    else if(isupper(trans_string[i]) && (trans_string[i] + 13 > 90))
    {
        trans_string[i] = 64 + (trans_string[i] + 13) % 90;
    }
    else if(islower(trans_string[i]) && (trans_string[i] + 13 <= 122))
    {
         trans_string[i] = trans_string[i] + 13;
    }
    else if(islower(trans_string[i]) && (trans_string[i] + 13 > 122))
    {
        trans_string[i] = 96 + (trans_string[i] + 13) % 122;
    }
}


return trans_string;
}


  