#ifndef MULTI_H
#define MULTI_H


#include "TextInput.hpp"
#include "TextOutput.hpp"
#include "TextTransformer.hpp"


class Multi: public TextTransformer{
public:
   
    Multi(std::string a_transformations);

    std::string incoding(std::string a_string);

private:
    
    std::string m_string;
    std::string m_transformations;
};

TextTransformer* get_transform_multi(std::string const& a_trans);

#endif