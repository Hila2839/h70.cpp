#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H


#include <vector>
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"



class VirtualMachine
{
public:
    VirtualMachine(size_t a_stack_size, size_t a_data_memory_size, size_t a_orders_memory_size, const char* a_file_name);
    void run();

    Ip& get_ip();
    
    Memory& get_memory();

    void set_memory(Memory& a_memory);
    void init_memory();

    Stack& get_stack();
    
private:
    Stack m_stack;
    Ip m_ip;
    Memory m_memory;
    const char* m_file_name;
};



#endif