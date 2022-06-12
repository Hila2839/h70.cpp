#ifndef TEXTOUTPUT_H
#define TEXTOUTPUT_H




#include <string>

class TextOutput{
public:
    virtual void output(std::string const& a_string) = 0;
    virtual ~TextOutput(){};
};

#endif