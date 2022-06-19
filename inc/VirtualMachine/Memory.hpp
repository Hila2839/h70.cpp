#ifndef MEMORY_H
#define MEMORY_H

#include <cstddef>
#include <vector>
#include <cstddef>

#include "Instruction.hpp"

class Instruction;

class Memory
{
public:
    Memory(size_t a_data_memory_size, size_t a_orders_memory_size);
    Memory(size_t a_data_memory_size, size_t a_orders_memory_size, std::vector<Instruction*> a_orders_memory);
    ~Memory();

    Instruction* get_Instruction(size_t a_orders_index) const;
    unsigned long const& get_data(size_t a_data_index) const;
    void set_data(size_t a_data_index, unsigned long const& a_data);
    void set_orders_to_memory(std::vector<Instruction*> a_instructions);
    void push_data(unsigned long const& a_data);
    void init_data_memory();


private:
    size_t m_data_memory_size;
    size_t m_orders_memory_size;
    std::vector<Instruction*> m_orders_memory;
    std::vector<unsigned long> m_data_memory;
};

#endif