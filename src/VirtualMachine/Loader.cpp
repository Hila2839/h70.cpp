#include "Loader.hpp"
#include "Instruction.hpp"
#include "Parcer.hpp"
#include "Mapper.hpp"
#include "Num.hpp"



Loader::Loader(const char* a_file_name)
: m_file_name(a_file_name)
{
}


std::vector<Instruction*> Loader::memory_create(Ip& a_ip, Memory& a_memory, Stack& a_stack)
{
    std::vector<std::string> const& words = from_file(m_file_name);

    std::vector<Instruction*> instructions;

    std::vector<std::string>::const_iterator begin = words.begin();
    std::vector<std::string>::const_iterator end = words.end();

    Mapper map;
    while(begin != end)
    {
        size_t found = (*begin).find(" ",0);
        if (found < (*begin).size())
        {
            std::string instruction = (*begin).substr(0,found);
            if (*begin == "PUSH")
            {
                std::string param = (*begin).substr(found);
                instructions.push_back(map.find_instruction(instruction,a_ip, a_memory, a_stack));
                Instruction* num = new NUM(a_ip, a_stack, param);
                instructions.push_back(num);
            }   
        
        }
        else
        {
            instructions.push_back(map.find_instruction(*begin,a_ip, a_memory, a_stack));
            ++begin;
        }
    }
    
    return instructions;
}

