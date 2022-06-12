#ifndef ROT13_H
#define ROT13_H



#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"


class Rot13: public TextTransformer{
public:
    std::string incoding(std::string const& a_string);
    static std::string const& get_name();

protected:
    static std::string m_name;

};



#endif