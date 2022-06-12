#ifndef FACTORY_H
#define FACTORY_H

#include <map>

#include "TextTransformer.hpp"

typedef TextTransformer*(*funcPointer)(void);

class Factory
{
public:
    Factory();
    TextTransformer* create(std::string a_name);

private:
    std::map<std::string,funcPointer> m_map;
};


#endif