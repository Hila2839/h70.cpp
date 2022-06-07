#include <string>
#include <cassert>
#include <fstream>

#include "FromFile.hpp"
#include "TextInput.hpp"

FromFile::FromFile(char* a_file_name)
: TextInput()
, m_file_name(a_file_name)
{
}

std::string FromFile::input()
{
std::ifstream file_name(m_file_name);
assert(file_name.is_open() && "failed to open a new file");


char ch;
while(!file_name.eof())
{
        file_name >> ch;
        m_string.push_back(ch);
           
}
file_name.close();
return m_string;
}
