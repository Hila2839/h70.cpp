#ifndef LABEL_H
#define LABEL_H


#include <string>

#include "Instruction.hpp"




class LABEL: public Instruction
{
public:
    LABEL(int a_number);
    void execute(Bus& a_bus);

    std::string get_label();
    void set_label_number(int a_number);
private:
    std::string m_operand;
    int m_label_num;
};

Instruction* create_label(std::string a_label);

#endif