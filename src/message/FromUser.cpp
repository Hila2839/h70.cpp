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
    std::string m_string;
    std::cout<<"enter a sentnce:\n";
    std::cin>>m_string;
    return m_string;
}