#include "Memory.hpp"

 Memory:: Memory(size_t a_memory_size)
 :m_memory_size(a_memory_size)
 {
 }


Memory::Memory(size_t a_memory_size, std::vector<Instruction*> a_orders_memory)
:m_memory_size(a_memory_size)
, m_orders_memory(a_orders_memory)
{
}

Memory::~Memory()
{
}

Instruction* Memory::get_Instruction(size_t a_orders_index) const
{
    return m_orders_memory[a_orders_index];
}


unsigned long const& Memory::get_data(size_t a_data_index) const
{
    return m_data_memory[a_data_index];
}


void Memory::set_data(size_t a_data_index, unsigned long const& a_data)
{
    m_data_memory[a_data_index] = a_data;
} 


void Memory::set_orders_to_memory(std::vector<Instruction*> a_instructions)
{
    m_orders_memory = a_instructions;
}
