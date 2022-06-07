#ifndef TEXTTRANSFORMER_H
#define TEXTTRANSFORMER_H



#include <string>

class TextTransformer
{
public:
    virtual std::string incoding() = 0;
    virtual ~TextTransformer(){};
};

#endif