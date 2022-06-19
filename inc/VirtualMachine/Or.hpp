#ifndef OR_HPP
#define OR_HPP

#include <string>

#include "BiInstruction.hpp"



class OR: public BiInstruction
{
public:
    static const std::string NAME;
    virtual int actual_op(int a_first, int a_second);
   
};

Instruction* create_or();

#endif