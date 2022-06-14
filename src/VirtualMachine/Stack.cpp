#include "Stack.hpp"


Stack::Stack()
{}

Stack::~Stack()
{}

void Stack::pop()
{
    m_stack.pop();
}

void Stack::push(int a_num)
{
    return m_stack.push(a_num);
}

int Stack::top()
{
    return m_stack.top();
}