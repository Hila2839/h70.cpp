#ifndef ADD_HPP
#define ADD_HPP

#include <string>

#include "BiInstruction.hpp"



class ADD: public BiInstruction
{
public:
    static const std::string NAME;
    virtual int actual_op(int a_first, int a_second);
   
};

Instruction* create_add();

#endif