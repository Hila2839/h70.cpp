#include <string>

#include "Or.hpp"



const std::string OR::NAME = "OR";


Instruction* create_or()
{
    return new OR();
}

int OR::actual_op(int a_first, int a_second)
{
    return a_first | a_second;
}




/*
 void OR::execute()
 {
    int a = m_stack.pop();
    int b = m_stack.pop();
    m_stack.push(a & b);
    m_ip.next();
 }*/