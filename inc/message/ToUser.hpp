#ifndef TOUSER_H
#define TOUSER_H




#include <string>
#include <cstring>

#include "TextOutput.hpp"



class ToUser :public TextOutput{
public:
    //ToUser();
    void output(std::string a_string);
private:
    std::string m_string;
};



#endif