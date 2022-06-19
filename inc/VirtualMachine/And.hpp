#ifndef AND_HPP
#define AND_HPP

#include <string>

#include "BiInstruction.hpp"



class AND: public BiInstruction
{
public:
    static const std::string NAME;
    virtual int actual_op(int a_first, int a_second);
   
};

Instruction* create_and();

#endif