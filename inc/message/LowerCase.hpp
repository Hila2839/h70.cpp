#ifndef LOWERCASE_H
#define LOWERCASE_H


#include <iostream>
#include <cstring>
#include <string>

#include "TextTransformer.hpp"

class LowerCase: public TextTransformer{
public:
   // LowerCase(std::string a_string);
    std::string incoding(std::string const& a_string);
    static std::string const& get_name();

protected:
    static std::string m_name;
};

#endif
