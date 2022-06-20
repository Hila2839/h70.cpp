#include "Loader.hpp"
#include "Instruction.hpp"
#include "Parcer.hpp"
#include "Mapper.hpp"
#include "Num.hpp"
#include "Ipnum.hpp"
#include "AddrNum.hpp"




Loader::Loader(const char* a_file_name)
: m_file_name(a_file_name)
{
}


std::vector<Instruction*> Loader::memory_create()
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
            if (instruction == "PUSH")
            {
                std::string param = (*begin).substr(found);
                Instruction* num = new NUM(param);
                instructions.push_back(map.find_instruction(instruction));
                instructions.push_back(num);
                ++begin;
            }   
            if (instruction == "PUSHIP")
            {
                std::string param = (*begin).substr(found);
                Instruction* num = new IPNUM(param);
                instructions.push_back(map.find_instruction(instruction));
                instructions.push_back(num);
                ++begin;
            }   
            if (instruction == "JG" ||instruction == "JLE"
                    ||instruction == "JL"||instruction == "JE")
            {
                std::string param = (*begin).substr(found);
                Instruction* num = new AddrNUM(param);
                instructions.push_back(map.find_instruction(instruction));
                instructions.push_back(num);
                ++begin;
            }   
             
        
        }
        else
        {
            instructions.push_back(map.find_instruction(*begin));
            ++begin;
        }
    }
    
    return instructions;
}

