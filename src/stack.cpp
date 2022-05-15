#include <cstdio>
#include <cassert>

#include "stack.hpp"


#define MAGIC 5826


namespace adt
{


Stack::Stack(int a_size)
: m_size(a_size)
, m_items_num(0)
, magic_num(MAGIC)
{
    //int stack_array[a_size] = {0};
    int stack_array[16] = {0};
    m_stack_array = stack_array;
    assert(m_size != 0 && "size can't be zero");  
}

Stack::Stack()
: m_size(16) 
, m_items_num(0)
, magic_num(MAGIC)              
{    
    int stack_array[16] = {0};
    m_stack_array = stack_array;
}


void Stack::push(int a_number)
{
    if(m_items_num < m_size)
    {
        m_stack_array[m_items_num] = a_number;
        m_items_num++;
    }
    else
    {
        assert( "overflow");
    }
}

int Stack::pop()
{
    if(m_items_num == 0)
    {
        assert( "underflow");
        //return 0;
    }
    else
    {
        int deleted = m_stack_array[m_items_num];
        m_items_num--;
        return  deleted;
    }
}

void Stack::clear()
{
    for (int i = 0; i < m_items_num ; i++)
    {
        m_stack_array[i] = 0;
    }
}


void Stack::print()
{
    for (int i = 0; i < m_items_num ; i++)
    {
        printf("%d, ", m_stack_array[i]);
    }
    printf("\n ");
}


int& Stack::top()
{
    if(m_items_num == 0)
    {
         assert( "underflow");
       
    }
    else
    {
        return m_stack_array[m_items_num - 1];
    }
}

int Stack::get_size()
{
    return m_items_num;
}

void Stack::operator+=(Stack a_other)
{
    for(int i = 0; i < a_other.m_items_num; ++i)
    {
        int j = m_items_num;
        m_stack_array[j] = a_other.m_stack_array[i];
        j++;
        m_size ++;
    }
}

void Stack::operator<<(Stack a_other)
{
    for(int i = 0; i < a_other.m_items_num; ++i)
    {
        int j = m_items_num;
        m_stack_array[j] = a_other.m_stack_array[i];
        j++;
        m_items_num ++;
    }
    a_other.m_items_num = 0;
}

void Stack::operator>>(Stack a_other)
{
    for(int i = 0; i < m_items_num; ++i)
    {
        int j = a_other.m_items_num;
         a_other.m_stack_array[j] = m_stack_array[i];
        j++;
         a_other.m_items_num ++;
    }
    m_items_num = 0;
}




}//namespace adt