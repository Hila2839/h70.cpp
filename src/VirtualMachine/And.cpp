#include <string>

#include "And.hpp"



const std::string AND::NAME = "AND";


Instruction* create_and()
{
    return new AND();
}

int AND::actual_op(int a_first, int a_second)
{
    return a_first & a_second;
}




/*
 void AND::execute()
 {
    int a = m_stack.pop();
    int b = m_stack.pop();
    m_stack.push(a & b);
    m_ip.next();
 }*/