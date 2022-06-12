#ifndef CENSOR_H
#define CENSOR_H



#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"


class Censor: public TextTransformer{
public:
    Censor();
    std::string incoding(std::string const& a_string);
    static std::string const& get_name();

protected:
    static std::string m_name;
};



#endif