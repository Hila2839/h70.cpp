#ifndef FROMUSER_H
#define FROMUSER_H

#include <string>
#include <iostream>

#include "TextInput.hpp"

class FromUser :public TextInput{
public:
    FromUser();
    std::string input();

private:
    std::string m_string;
};




#endif

