#ifndef MAPPER_H
#define MAPPER_H

#include <map>
#include <string>
#include <functional>
#include <cstdint>

#include "Bus.hpp"



enum OpCode
{
    ADD,
    SUB,
    AND, 
    OR, 
    XOR, 
    JZ, 
    JNZ, 
    JMP, 
    NOT, 
    DUP, 
    SWAP,
    NOP,
    PUSH,
    IN,
    OUT,
    HLT,
    LOAD,
    DROP,
    STOR,
    ROL3,
    OUTNUM,
    INNUM,
    COMPL,
    POPIP,
    DROPIP,
    JG,
    JE,
    JL,
    JLE,
    JGI,
    JGE,
    PUSHIP
};

using func = std::function<void()>;

class Mapper
{
public:
    Mapper();

    Mapper(Bus& a_bus);

    //func find_instruction(int64_t  a_word);
    std::map<std::string, OpCode> const& opcodes_map();
    std::map<OpCode, func> const& functions_map();
    int64_t from_string_to_enum(std::string a_word);

    OpCode operator[](int64_t a_opcode);
    int64_t operator[](std::string const& a_opcode);
    func const& operator[](OpCode a_opcode); 
    


    
private:
    std::map<std::string, OpCode> m_opcode;
    std::map<OpCode, func> m_map;
    //Bus& m_bus;
};

OpCode instruction_convert(std::string a_word);




#endif