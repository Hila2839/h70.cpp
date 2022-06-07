#ifndef FROMFILE_H
#define FROMFILE_H




#include <string>

#include "TextInput.hpp"

class FromFile :public TextInput{
public:
    FromFile(const char* a_file_name);
    std::string input();

private:
    const char* m_file_name;
    std::string m_string;
};



#endif