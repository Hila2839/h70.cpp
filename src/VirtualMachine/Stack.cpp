#include "Stack.hpp"


Stack::Stack(size_t a_stack_capacity)
: m_size(0)
, m_capacity(a_stack_capacity)
{}

Stack::~Stack()
{}

int Stack::pop()
{
    if(m_size == 0)
    {
        //throw UnderflowError("stack:pop", "underflow");
    }
    int poped = m_stack.top();
    m_stack.pop();
    --m_size;
    return poped;
}

void Stack::push(int a_num)
{
    if(m_size >= m_capacity)
    {
        //throw OverflowError("stack:push", "overflow");
    }
    m_stack.push(a_num);
    ++m_size;
}


const int Stack::top() const
{
    if(m_size == 0)
    {
        //throw UnderflowError("stack:pop", "underflow");
    }
    return m_stack.top();
}

size_t Stack::get_size() const
{
    return m_size;
}


void Stack::print() const
{
    std::stack<int> my_copy = m_stack;
    while(!my_copy.empty())
    {
        std::cout<<my_copy.top()<<", ";
        my_copy.pop();
    }
    
}
