#include <string>
#include <cassert>
#include <cstring>
#include <fstream>

#include "ToFile.hpp"
#include "TextOutput.hpp"

ToFile::ToFile(char* a_file_name, std::string a_string)
: TextOutput()
, m_file_name(a_file_name)
, m_string(a_string)
{
}

void ToFile::output(std::string)
{

    std::ofstream file;
    
    file.open(m_file_name);

    assert(file && "file open filure, need more channel");
    
    for (size_t i = 0; i < m_string.size(); i++)
    {
       file<< m_string[i];
    }

    file.close();
}

