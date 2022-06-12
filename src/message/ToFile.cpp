#include <string>
#include <cassert>
#include <cstring>
#include <fstream>

#include "ToFile.hpp"
#include "TextOutput.hpp"

ToFile::ToFile(const char* a_file_name)
: TextOutput()
, m_file_name(a_file_name)
{
}

void ToFile::output(std::string const& a_string)
{

    std::ofstream file;
    
    file.open(m_file_name);

    assert(file && "file open filure, need more channel");
    
    for (size_t i = 0; i < a_string.size(); i++)
    {
       file<< a_string[i];
    }

    file.close();
}

