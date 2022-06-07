#ifndef TOUSER_H
#define TOUSER_H




#include <string>
#include <cstring>

#include "TextOutput.hpp"



class ToUser :public TextOutput{
public:
    ToUser(std::string a_string);
    virtual void output() = 0;
private:
    std::string m_string;
};



#endif