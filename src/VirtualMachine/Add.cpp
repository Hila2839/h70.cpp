#include <string>

#include "Add.hpp"


const std::string ADD::NAME = "ADD";


Instruction* create_add()
{
    return new ADD();
}

int ADD::actual_op(int a_first, int a_second)
{
    return a_first + a_second;
}




/*
 void ADD::execute()
 {
    int a = m_stack.pop();
    int b = m_stack.pop();
    m_stack.push(a & b);
    m_ip.next();
 }*/