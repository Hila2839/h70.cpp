#ifndef INSTRUCTIONSFUNCTIONS_H
#define INSTRUCTIONSFUNCTIONS_H


#include <map>

#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"

/*
void push(std::stack<int>& stk, std::vector<int>& memory, int& ip) 
{
    int n = memeory[ip]
    stk.push(n); 
    ++ ++ip;
}*/
/*
int pop(std::stack<int>& stk) 
{ 
    auto r = stk.top(); 
    stk.pop(); 
    return r; 
}*/



void add(std::stack<int>& a_stack);



void sub(std::stack<int>& a_stack);
   


#endif// INSTRUCTIONSFUNCTIONS_H