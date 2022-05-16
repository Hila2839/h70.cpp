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
    void push(int a_number);
    int pop();
    void clear();
    int& top() const;
    int get_size() const;
    void operator+=(Stack a_other);
    Stack& operator<<(Stack& a_other);
    Stack& operator>>(Stack& a_other);



    
private:
    size_t m_capacity;
    size_t m_size;
    int *m_stack_array;
};



}//namespace adt

#endif