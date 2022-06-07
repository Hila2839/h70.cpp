#ifndef LOWERCASE_H
#define LOWERCASE_H


#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"

class LowerCase: public TextTransformer{
public:
    LowerCase(std::string a_string);
    std::string incoding();

private:
    std::string m_string;
};

#endif
