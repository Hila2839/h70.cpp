#ifndef MAPPER_H
#define MAPPER_H

#include <map>
#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"


typedef Instruction* (*funcPointer)();

class Mapper
{
public:
    Mapper();
    Instruction* find_instruction(std::string const& a_word);
    
private:
    std::map<std::string, funcPointer> m_map;
    
};




#endif