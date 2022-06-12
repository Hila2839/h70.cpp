#ifndef TEXTTRANSFORMER_H
#define TEXTTRANSFORMER_H



#include <string>

class TextTransformer
{
public:
    virtual std::string incoding(std::string const& a_string) = 0;
    virtual ~TextTransformer(){};
};

#endif