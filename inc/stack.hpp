#ifndef STACK_H
#define STACK_H 

#include "rational.hpp"



namespace adt
{


class Stack
{
public:
    /**
     * @brief Construct a new Stack object
     * 
     * @param a_size 
     */
    Stack(int a_size);

    /**
     * @brief Construct a new Stack object
     * 
     */
    Stack();

    
    /**prints the stack
     * @brief 
     * 
     */
    void print();
    void push(int a_number);
    int pop();
    void clear();
    int& top();
    int get_size();
    void operator+=(Stack a_other);
    void operator<<(Stack a_other);
    void operator>>(Stack a_other);



    
private:
    int m_size;
    int m_items_num;
    int magic_num;
    int *m_stack_array;
};



}//namespace adt

#endif