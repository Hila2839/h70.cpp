#include <vector>//vector
#include <iostream>
#include <fstream>//file

#include "Parcer.hpp"
#include "FileError.hpp"

std::vector<std::string> from_file(const char* a_file_name)
{
std::ifstream input_file(a_file_name);
if(!input_file.is_open())
{
    throw FileError("from_file", "failed to open a new file");
}

std::vector<std::string> orders;
std::string order;

while(getline(input_file, order))
{
    orders.push_back(order);
}

input_file.close();
return orders;
}

