#ifndef MULTI_H
#define MULTI_H

#include <list>
#include <vector>


#include "TextInput.hpp"
#include "TextOutput.hpp"
#include "TextTransformer.hpp"



class Multi: public TextTransformer{
public:
   
    Multi(std::string a_transformations, char a_delimeter);

    std::list<std::string> parcer();

    std::vector<TextTransformer*> vector_create(std::list<std::string> a_names);

    std::string trans_sequence(std::vector<TextTransformer*> a_names);

    std::string incoding(std::string a_string);

private:
    
    std::string m_string;
    std::string m_transformations;
    char m_delimeter;
};

//TextTransformer* get_transform_multi(std::string const& a_trans);

#endif