#ifndef CENSOR_H
#define CENSOR_H



#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"


class Censor: public TextTransformer{
public:
    Censor(std::string a_string);
    virtual std::string incoding();

private:
    std::string m_string;
};



#endif