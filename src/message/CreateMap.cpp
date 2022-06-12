#include <map>
#include "factory.hpp"
#include "CreateMap.hpp"

TextTransformer* create_upper();
TextTransformer* create_lower();
TextTransformer* create_censor();
TextTransformer* create_rot13();



 CreateMap::CreateMap()
 {
    std::map<std::string,funcPointer> m;
    m_map = m;

    m_map["rot13"] = &create_rot13;
    m_map["upper"] = &create_upper;
    m_map["lower"] = &create_lower;
    m_map["censor"] = &create_censor;
 }

