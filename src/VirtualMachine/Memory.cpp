#include <iostream>
#include "Memory.hpp"
#include "OutOfRangeError.hpp"

 Memory:: Memory(size_t a_data_memory_size, size_t a_orders_memory_size)
 :m_data_memory_size(a_data_memory_size)
 , m_orders_memory_size(a_orders_memory_size)
 , m_orders_memory(a_orders_memory_size)
, m_data_memory(a_data_memory_size)
 {
 }


Memory::Memory(size_t a_data_memory_size, size_t a_orders_memory_size, std::vector<Instruction*> a_orders_memory)
:m_data_memory_size(a_data_memory_size)
, m_orders_memory_size(a_orders_memory_size)
, m_orders_memory(a_orders_memory)
{
}

Memory::~Memory()
{
}

Instruction* Memory::get_Instruction(size_t a_orders_index) const
{
    if (a_orders_index >= m_orders_memory_size)
    {
        throw OutOfRangeError("Memory::set_Instruction", "out of range");

    }
    
    return m_orders_memory[a_orders_index];
}


unsigned long const& Memory::get_data(size_t a_data_index) const
{
    if (a_data_index >= m_data_memory_size)
    {
            throw OutOfRangeError("Memory::get_data", "out of range");

    }
    return m_data_memory.at(a_data_index);
}


void Memory::set_data(size_t a_data_index, unsigned long const& a_data)
{
    if (a_data_index >= m_data_memory_size)
    {
        throw OutOfRangeError("Memory::set_data", "out of range");
    }
    m_data_memory.at(a_data_index) = a_data;  

} 


void Memory::init_data_memory()
{
    for (size_t i = 0; i < m_data_memory_size; i++)
    {
        m_data_memory.push_back(0);
    }
    for (size_t i = 0; i < m_orders_memory_size; i++)
    {
        m_orders_memory.push_back(0);
    }
    
}


void Memory::set_orders_to_memory(std::vector<Instruction*> a_instructions)
{
    m_orders_memory = a_instructions;
}
