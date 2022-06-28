#include <vector>

#include "Bus.hpp"
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"





Bus::Bus(Stack& a_stack, Ip& a_ip, Memory& a_memory, Stack& a_ip_stack)
: m_stack(a_stack)
, m_ip(a_ip)
, m_memory(a_memory)
, m_ip_stack(a_ip_stack)
{
}

Bus::~Bus()
{
}


//orders stack managenent
void Bus::push_to_stack(int a_data)
{
    m_stack.push(a_data);
}

int Bus::pop_from_stack()
{
    return m_stack.pop();
}

int Bus::top_of_stack()
{
    return m_stack.top();
}

//stack_ip managenent
void Bus::push_to_ip_stack(int a_order_index)
{
    m_ip_stack.push(a_order_index);
}

int Bus::pop_from_ip_stack()
{
    return m_ip_stack.pop();
}

int Bus::top_of_ip_stack()
{
    return m_ip_stack.top();
}



//ip management
void Bus::move_ip_to(int a_index)
{
    m_ip.jump_to(a_index);
}

void Bus::ip_next()
{
    m_ip.next();
}

void Bus::ip_back()
{
    m_ip.prev();
}

int Bus::get_ip()
{
    return m_ip.get_ip();
}


//data memory management
int Bus::get_Instruction(size_t a_orders_index) const
{
    return m_memory.get_Instruction(a_orders_index);
}

unsigned long const& Bus::get_data(size_t a_data_index) const
{
    return m_memory.get_data(a_data_index);
}
void Bus::set_data(size_t a_data_index, unsigned long const& a_data)
{
    m_memory.set_data(a_data_index, a_data);
}

void Bus::push_data(unsigned long const& a_data)
{
    m_memory.push_data(a_data);
}
   
