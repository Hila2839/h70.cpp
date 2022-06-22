#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <string>
#include <map>

#include "Instruction.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"





class Loader
{
public:
    Loader(const char* a_file_name);

    std::vector<std::string> const& parcer() const;

    std::vector<Instruction*> memory_create();

    void insert_labels(std::string a_label);


    void labels_to_numbers(std::string a_label, int a_ip);

    //void convert_all_labels(std::vector<std::string> const& a_words);




private:
    const char* m_file_name;
    std::map<std::string, int> m_labels_map;
};





#endif