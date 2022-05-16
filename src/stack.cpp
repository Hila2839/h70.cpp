#include <cstdio>
#include <cassert>
#include <cstdlib>

#include "stack.hpp"
#include <cstddef>


#define MAGIC 5826



namespace calc
{

size_t my_min(size_t a_lhs, size_t a_rhs)
{
    if(a_lhs < a_rhs)
    {
        return a_lhs;
    }
    else
    {
        return a_rhs;
    }
}

}//namespace calc

namespace adt
{

//explicit
Stack::Stack(size_t a_size)
: m_capacity(a_size)
, m_size(0)
{
    m_stack_array = (static_cast<int*>(::malloc( m_capacity * sizeof(int))));
    assert(m_stack_array && "malloc filure, need more core");  
}

Stack::Stack()
: m_capacity(16) 
, m_size(0)              
{    
    m_stack_array =(static_cast<int*>(::malloc( m_capacity * sizeof(int))));
     assert(m_stack_array && "malloc filure, need more core");  
}


void Stack::push(int a_number)
{
    assert(m_size < m_capacity && "overflow");
    m_stack_array[m_size] = a_number;
    m_size++;
}

int Stack::pop()
{
    int t = top();
    m_size--;
    return t;
}

void Stack::clear()
{
    m_size = 0;
}


void Stack::print() const
{
    printf("[");
    for (size_t i = 0; i < m_size; i++)
    {
        printf("%d", m_stack_array[i]);
        if(i < m_size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n ");
}


int& Stack::top() const
{
    assert(m_size > 0 && "underflow");
    int n = m_stack_array[m_size - 1];
    int& r = n;
    return r;
}

int Stack::get_size() const
{
    return m_size;
}

void Stack::operator+=(Stack a_other)
{
    *this << a_other;//because its a copy it wont be deleted
    //for(size_t i = 0; i < a_other.m_size; ++i)
    //{
    //    int j = m_size;
    //    m_stack_array[j] = a_other.m_stack_array[i];
    //    j++;
    //    m_size ++;
    //}
}

Stack& Stack::operator<<(Stack& a_other)
{
    size_t n = a_other.m_size;
    size_t d = m_capacity - m_size;
    size_t take = calc::my_min(d, n);
    for(size_t i = 0; i < take; ++i)
    {
        push(a_other.pop());
    }
    return *this;
}


Stack& Stack::operator>>(Stack& a_other)
{
    a_other << *this;
    return *this;
}




}//namespace adt