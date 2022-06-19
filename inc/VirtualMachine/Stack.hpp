#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstddef>
#include <stack>


class Stack
{
public:
    Stack(size_t a_stack_size);
    ~Stack();
    int pop();
    void push(int a_num);
    const int top() const;
    size_t get_size() const;
    void print() const;

private:
    std::stack<int> m_stack;
    size_t m_size;
    size_t m_capacity;
};



#endif