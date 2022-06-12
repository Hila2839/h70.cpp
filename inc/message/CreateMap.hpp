#ifndef MAPCREATE_H
#define MAPCREATE_H

#include <map>

#include "TextTransformer.hpp"


typedef TextTransformer*(*funcPointer)(void);

class CreateMap
{
public:
    CreateMap();
private:
    std::map<std::string,funcPointer> m_map;
};


#endif