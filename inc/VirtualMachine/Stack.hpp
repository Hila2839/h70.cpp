#ifndef STACK_H
#define STACK_H


#include <cstddef>
#include <stack>


class Stack
{
public:
    Stack();
    ~Stack();
    void pop();
    void push(int a_num);
    int top();


private:
    std::stack<int> m_stack;
    size_t m_size;

};



#endif