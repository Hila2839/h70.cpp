#ifndef BUS_H
#define BUS_H


#include <vector>
#include "Stack.hpp"
#include "Memory.hpp"
#include "Ip.hpp"

class Ip;
class Memory;
class Instruction;
class Stack;


class Bus
{
public:
    Bus(Stack& a_stack, Ip& a_ip, Memory& a_memory, Stack& a_ip_stack);
    ~Bus();

    //orders stack managenent
    void push_to_stack(int a_data);
    int pop_from_stack();
    int top_of_stack();

    //stack_ip managenent
    void push_to_ip_stack(int a_order_index);
    int pop_from_ip_stack();
    int top_of_ip_stack();



    //ip management
    void move_ip_to(int a_index);
    void ip_next();
    void ip_back();
    int get_ip();


    //data memory management
    Instruction* get_Instruction(size_t a_orders_index) const;
    unsigned long const& get_data(size_t a_data_index) const;
    void set_data(size_t a_data_index, unsigned long const& a_data);
    void push_data(unsigned long const& a_data);
   

    
    
private:
    Stack& m_stack;
    Ip& m_ip;
    Memory& m_memory;
    Stack& m_ip_stack;
};



#endif