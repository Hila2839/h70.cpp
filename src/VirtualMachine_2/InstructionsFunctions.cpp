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


void add(std::stack<int>& a_stack)
{
    int a = a_stack.pop();
    int b = a_stack.pop();
    a_stack.push(a + b);
}


void sub(std::stack<int>& a_stack)
{
    int a = a_stack.pop();
    int b = a_stack.pop();
    a_stack.push(a - b);
}


//firmware[PUSH] = std::bind(push, std::ref(s), std::ref(code), std::ref(ip));
    