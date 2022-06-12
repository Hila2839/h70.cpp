#ifndef UPERCASE_H
#define UPERCASE_H


#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"
class UpperCase :public TextTransformer{
public:
   // UpperCase(std::string a_string);
    std::string incoding(std::string const& a_string);
    static std::string const& get_name();

protected:
    static std::string m_name;
};

#endif