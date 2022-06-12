#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <list>
#include <vector>

#include "TextTransformer.hpp"

typedef TextTransformer*(*funcPointer)(void);

class Factory
{
public:
    Factory();
    std::vector<TextTransformer*> vector_create(std::list<std::string> a_names);

    TextTransformer* create(std::string const& a_name);

private:
    std::map<std::string,funcPointer> m_map;
};


#endif