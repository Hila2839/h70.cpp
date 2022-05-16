#ifndef STACK_H
#define STACK_H 


#include <cstddef>



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
    explicit Stack(size_t a_size);


    /**
     * @brief Construct a new Stack object
     * 
     */
    Stack();

    
    /**prints the stack
     * @brief 
     * 
     */
    void print() const;

    /**
     * @brief push number to end of stack
     * 
     * @param a_number 
     */
    void push(int a_number);


    /**
     * @brief pop out tha last number in stack
     * 
     * @return int 
     */
    int pop();


    /**
     * @brief clear all items from stack
     * 
     */
    void clear();


    /**
     * @brief return the number from the end of stack
     * 
     * @return int& 
     */
    int& top() const;


    /**
     * @brief Get the number of objects in stack
     * 
     * @return int 
     */
    int get_size() const;


    /**
     * @brief add other stack to self stack
     * 
     * @param a_other 
     */
    void operator+=(Stack a_other);


    /**
     * @brief add other stack to self stack and delete the other
     * 
     * @param a_other 
     * @return self Stack 
     */
    Stack& operator<<(Stack& a_other);


    /**
     * @brief  add self stack to other stack and delete the self
     * 
     * @param a_other 
     * @return self Stack
     */
    Stack& operator>>(Stack& a_other);



    
private:
    size_t m_capacity;
    size_t m_size;
    int *m_stack_array;
};



}//namespace adt

#endif