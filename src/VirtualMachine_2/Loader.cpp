#include <iostream>
#include <stdlib.h>


#include "Loader.hpp"
#include "Parcer.hpp"
#include "Mapper.hpp"





Loader::Loader(const char* a_file_name)
: m_file_name(a_file_name)
{
}


std::vector<int64_t> Loader::memory_create()
{
    std::vector<std::string> words = from_file(m_file_name);

    std::vector<int64_t> instructions;

    std::vector<std::string>::const_iterator begin = words.begin();
    std::vector<std::string>::const_iterator end = words.end();

    
    Mapper map;

    
     while(begin != end)
    {
        std::cout<<(*begin)<<",";

        size_t found = (*begin).find(" ",0);
        
        if (found < (*begin).size())
        {
            std::string instruction = (*begin).substr(0,found);
            if (instruction == "PUSH")
            {
                std::string param = (*begin).substr(found);

                int64_t number = map.from_string_to_enum(instruction);
                std::cout<<"enum:"<<number<<'\n';
                instructions.push_back(number);
                instructions.push_back(atoi(param.c_str()));
            }   
            
            if (instruction == "PUSHIP")
            {
                std::string param = (*begin).substr(found);

                int64_t number = map.from_string_to_enum(instruction);
                std::cout<<"enum:"<<number<<'\n';
                instructions.push_back(number);
                instructions.push_back(atoi(param.c_str()));

                //auto label_key = m_labels_map.find(param);
                //int ip = label_key->second;
                
            } 

            if (instruction == "JG" ||instruction == "JLE"
                    ||instruction == "JL"||instruction == "JE")
            {
                std::string param = (*begin).substr(found);

                int64_t number = map.from_string_to_enum(instruction);
                std::cout<<"enum:"<<number<<'\n';
                instructions.push_back(number);
                instructions.push_back(atoi(param.c_str()));                
            }   
             
        
        }
        else
        {
            int64_t number = map.from_string_to_enum(*begin);
            std::cout<<"enum:"<<number<<'\n';
            instructions.push_back(number);
        }
        ++begin;
        
    }
    std::cout<<'\n';
    return instructions;
}

/*
    int place_counter = 0;
    std::string label ;
    while(begin != end)
    {
        size_t delimiter = (*begin).find(":",0);
        size_t found = (*begin).find(" ",0);
        
        if (found < (*begin).size())
        {
            ++place_counter;
        }
        if (delimiter < (*begin).size())
        {
            label = (*begin).substr(0,delimiter);

            int ip = place_counter + 1;
            labels_to_numbers(label,ip);

        }
        ++place_counter;
        ++begin;
    }

    begin = words.begin();
    end = words.end();
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
                std::string param = (*begin).substr(found + 1);
                auto label_key = m_labels_map.find(param);
                int ip = label_key->second;
                
                Instruction* label = new LABEL(ip);
                instructions.push_back(map.find_instruction(instruction));
                instructions.push_back(label);
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
            size_t delimiter = (*begin).find(":",0);
            if(delimiter >= (*begin).size())
            {
                instructions.push_back(map.find_instruction(*begin));
                ++begin;
            }
            else
            {
                 ++begin;
            }
        }
    }
    return instructions;
}*/




/*


void Loader::insert_labels(std::string a_label)
{
    if(m_labels_map.find(a_label) == m_labels_map.end())
    {
        m_labels_map[a_label] = (-1);
    }
}


void Loader::labels_to_numbers(std::string a_label, int a_ip)
{
     m_labels_map[a_label] = a_ip;
}


void Loader::convert_all_labels(std::vector<std::string> const& a_words)
{
    auto begin = a_words.begin();
    auto end = a_words.end();

    while(begin != end)
    {
        if (m_labels_map.find(*begin) != m_labels_map.end())
        {

            int number = m_labels_map[*begin.get_label()];
            *begin.set_label_number(number);
        }
        ++begin;
    }
}*/

