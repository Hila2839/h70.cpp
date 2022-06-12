#ifndef TOFILE_H
#define TOFILE_H




#include <string>

#include "TextOutput.hpp"



class ToFile :public TextOutput{
public:
    ToFile(const char* a_file_name);
    void output(std::string const& a_string);
private:
    const char* m_file_name;
    std::string m_string;
};



#endif