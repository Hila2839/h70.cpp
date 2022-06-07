#ifndef TEXTINPUT_H
#define TEXTINPUT_H





#include <string>

class TextInput{
public:
    virtual std::string input() = 0;
    virtual ~TextInput(){};
};


#endif
