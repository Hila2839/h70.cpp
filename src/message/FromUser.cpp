#include <string>
#include <iostream>

#include "FromUser.hpp"
#include "TextInput.hpp"

FromUser::FromUser()
: TextInput()
{
}

std::string FromUser::input()
{
    std::string new_string;
    std::string input;
    std::cout<<"enter a sentnce:\n";
    std::cout<<"press enter for a new line, and \"EOM\" to end message\n";
    
    std::getline(std::cin, input);
    
    while(input != "EOM")
    {
        new_string += input;
        new_string += '\n';
        std::getline(std::cin, input);
    }
    return new_string;
}