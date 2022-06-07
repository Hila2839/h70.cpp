#ifndef ROT13_H
#define ROT13_H



#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"


class Rot13: public TextTransformer{
public:
    virtual std::string incoding(std::string a_string);

private:
    std::string m_string;
};



#endif