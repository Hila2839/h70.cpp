#include <map>
#include <vector>
#include <list>

#include "factory.hpp"
/*
TextTransformer* create_upper();
TextTransformer* create_lower();
TextTransformer* create_censor();
TextTransformer* create_rot13();



 Factory::Factory()
 {
    std::map<std::string,funcPointer> m;
    m_map = m;

    m_map["rot13"] = &create_rot13;
    m_map["upper"] = &create_upper;
    m_map["lower"] = &create_lower;
    m_map["censor"] = &create_censor;
 }*/
std::vector<TextTransformer*> Factory::vector_create(std::list<std::string> a_names)
{
    std::vector<TextTransformer*> transformers;
    Factory factory;

    std::list<std::string>::iterator begin=  a_names.begin();
    std::list<std::string>::iterator end=  a_names.end();

    while(begin != end)
    {
        transformers.push_back(factory.create(*begin));
        begin++;
    }
    return transformers;
}


TextTransformer* Factory::create(std::string a_name)
{
     std::map<std::string,funcPointer>::iterator trans_create;
     trans_create = m_map.find(a_name);

     if(trans_create == m_map.end())
     {
         return 0;
     }

    return trans_create->second();
}

//get vector and loop on it to play it on the user string

