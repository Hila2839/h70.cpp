#ifndef UPERCASE_H
#define UPERCASE_H


#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"
class UpperCase :public TextTransformer{
public:
    UpperCase(std::string a_string);
    std::string incoding();

private:
    std::string m_string;
};

#endif