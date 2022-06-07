#include <string>
#include <cstring>

#include "Rot13.hpp"
#include "TextTransformer.hpp"

std::string Rot13::incoding(std::string a_string)
{
std::string string = string;
for(size_t i = 0; i <= string.size(); ++i)
{
    if(isupper(string[i]) && (string[i] + 13 <= 90))
    {
        string[i] = string[i] + 13;
    }
    else if(isupper(string[i]) && (string[i] + 13 > 90))
    {
        string[i] = 64 + (string[i] + 13) % 90;
    }
    else if(islower(string[i]) && (string[i] + 13 <= 122))
    {
         string[i] = string[i] + 13;
    }
    else if(islower(string[i]) && (string[i] + 13 > 122))
    {
        string[i] = 96 + (string[i] + 13) % 122;
    }
}


return string;
}


  