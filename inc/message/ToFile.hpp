#ifndef TOFILE_H
#define TOFILE_H




#include <string>

#include "TextOutput.hpp"



class ToFile :public TextOutput{
public:
    ToFile(char* a_file_name, std::string a_string);
    virtual void output(std::string a_string) = 0;
private:
    char* m_file_name;
    std::string m_string;
};



#endif