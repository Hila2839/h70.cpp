#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <string>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"

class Loader
{
public:
    Loader(const char* a_file_name);

    std::vector<std::string> const& parcer() const;

    std::vector<Instruction*> memory_create(Ip& a_ip, Memory& a_memory, Stack& a_stack);





private:
    const char* m_file_name;
};





#endif