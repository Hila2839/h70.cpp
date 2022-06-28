#include <iostream>

#include "Mapper.hpp"

#include "Bus.hpp"
#include "Loader.hpp"



Mapper::Mapper()
{
    m_opcode["ADD"] = OpCode::ADD;
    m_opcode["SUB"] = OpCode::SUB;
    m_opcode["OR"] = OpCode::OR;
    m_opcode["XOR"] = OpCode::XOR;
    m_opcode["AND"] = OpCode::AND;
    m_opcode["JZ"] = OpCode::JZ;
    m_opcode["JNZ"] = OpCode::JNZ;
    m_opcode["JMP"] = OpCode::JMP;
    m_opcode["NOT"] = OpCode::NOT;
    m_opcode["DUP"] = OpCode::DUP;
    m_opcode["SWAP"] = OpCode::SWAP;
    m_opcode["PUSH"] = OpCode::PUSH;
    m_opcode["NOP"] = OpCode::NOP;
    m_opcode["IN"] = OpCode::IN;
    m_opcode["OUT"] = OpCode::OUT;
    m_opcode["HLT"] = OpCode::HLT;
    m_opcode["LOAD"] = OpCode::LOAD;
    m_opcode["DROP"] = OpCode::DROP;
    m_opcode["STOR"] = OpCode::STOR;
    m_opcode["ROL3"] = OpCode::ROL3;
    m_opcode["OUTNUM"] = OpCode::OUTNUM;
    m_opcode["INNUM"] = OpCode::INNUM;
    m_opcode["COMPL"] = OpCode::COMPL;
    m_opcode["POPIP"] = OpCode::POPIP;
    m_opcode["DROPIP"] = OpCode::DROPIP;
    m_opcode["JG"] = OpCode::JG;
    m_opcode["JE"] = OpCode::JE;
    m_opcode["JL"] = OpCode::JL;
    m_opcode["JLE"] = OpCode::JLE;
    m_opcode["JGI"] = OpCode::JGI;
    m_opcode["JGE"] = OpCode::JGE;
    m_opcode["PUSHIP"] = OpCode::PUSHIP;
    

}



Mapper::Mapper(Bus& a_bus)
{

auto binary_arith = [&a_bus](auto op)
{
    auto first = a_bus.pop_from_stack();
    auto second = a_bus.pop_from_stack();
    auto result = op(first, second);
    a_bus.push_to_stack(result);
    a_bus.ip_next();
};


m_map[OpCode::ADD] = [&a_bus, binary_arith]()
{
    binary_arith(   [](auto first, auto second){return first + second;}   );
};

m_map[OpCode::SUB] = [&a_bus, binary_arith]()
{
    binary_arith(   [](auto first, auto second){return first - second;}   );
};

m_map[OpCode::AND] = [&a_bus, binary_arith]()
{
    binary_arith(   [](auto first, auto second){return first & second;}   );
};

m_map[OpCode::OR] = [&a_bus, binary_arith]()
{
    binary_arith(   [](auto first, auto second){return first | second;}   );
};

m_map[OpCode::XOR] = [&a_bus, binary_arith]()
{
    binary_arith(   []( auto first, auto second){return first ^ second;}   );
};


m_map[OpCode::JZ] = [&a_bus]()
{
    auto jump = a_bus.pop_from_stack();
    if(jump == 0)
    {
        a_bus.move_ip_to(jump);
    }
    else
    {
        a_bus.ip_next();
    }
};

m_map[OpCode::JNZ] = [&a_bus]()
{
    auto jump = a_bus.pop_from_stack();
    if(jump != 0)
    {
        a_bus.move_ip_to(jump);
    }
    else
    {
        a_bus.ip_next();
    }
};

m_map[OpCode::JMP] = [&a_bus]()
{
    auto jump = a_bus.pop_from_stack();
    a_bus.move_ip_to(jump);
};

m_map[OpCode::NOT] = [&a_bus]()
{
    auto first = a_bus.pop_from_stack();
    a_bus.push_to_stack(!first);

    a_bus.ip_next();
};

m_map[OpCode::DUP] = [&a_bus]()
{
    auto first = a_bus.pop_from_stack();
    a_bus.push_to_stack(first * 2);

    a_bus.ip_next();
};

m_map[OpCode::SWAP] = [&a_bus]()
{
    auto first = a_bus.pop_from_stack();
    auto second = a_bus.pop_from_stack();
    a_bus.push_to_stack(first);
    a_bus.push_to_stack(second);

    a_bus.ip_next();
};


m_map[OpCode::NOP] = [&a_bus]()
{
    a_bus.ip_next();
};


m_map[OpCode::PUSH] = [&a_bus]()
{
    a_bus.ip_next();
    
    a_bus.push_to_stack(a_bus.get_Instruction(a_bus.get_ip()));
    
    a_bus.ip_next();
};


m_map[OpCode::IN] = [&a_bus]()
{
    std::cout<<"enter a letter\n";
    int c = getchar();
    
    a_bus.push_to_stack(c);
    a_bus.ip_next();
};


m_map[OpCode::OUT] = [&a_bus]()
{
    char a = a_bus.pop_from_stack();
    std::cout<<a<<'\n';
    a_bus.ip_next();
};

m_map[OpCode::HLT] = [&a_bus]()
{
    exit(0);
};

m_map[OpCode::LOAD] = [&a_bus]()
{
    int adress = a_bus.pop_from_stack();
    int data = a_bus.get_data(adress);
    a_bus.push_to_stack(data);
    a_bus.ip_next();
};

m_map[OpCode::DROP] = [&a_bus]()
{
    a_bus.pop_from_stack();
    
    a_bus.ip_next();
};


m_map[OpCode::STOR] = [&a_bus]()
{
    int adress = a_bus.pop_from_stack();
    int data = a_bus.pop_from_stack();
    
    a_bus.set_data(adress, data);

    a_bus.ip_next();
};

m_map[OpCode::ROL3] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    int top_3 = a_bus.pop_from_stack();

    a_bus.push_to_stack(top_1);
    a_bus.push_to_stack(top_3);
    a_bus.push_to_stack(top_2);

    a_bus.ip_next();

};

m_map[OpCode::OUTNUM] = [&a_bus]()
{
    int a = a_bus.pop_from_stack();
    std::cout<<a<<'\n';
    a_bus.ip_next();
};

m_map[OpCode::INNUM] = [&a_bus]()
{
    std::cout<<"enter a number\n";
    int c;
    std::cin >> c;
    
    a_bus.push_to_stack(c);
    a_bus.ip_next();
};

m_map[OpCode::COMPL] = [&a_bus]()
{
    int a = a_bus.pop_from_stack();
    
    a_bus.push_to_stack(~a);
    a_bus.ip_next();
};

m_map[OpCode::POPIP] = [&a_bus]()
{
    int adress = a_bus.pop_from_ip_stack();
    a_bus.move_ip_to(adress);
};

m_map[OpCode::DROPIP] = [&a_bus]()
{
    a_bus.pop_from_ip_stack();
    a_bus.ip_next();
};


m_map[OpCode::JG] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    
    if (top_1 > top_2)
    {
        a_bus.ip_next();
        a_bus.move_ip_to(a_bus.get_Instruction(a_bus.get_ip()));
    }
    a_bus.ip_next();
};



m_map[OpCode::JE] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    
    if (top_1 == top_2)
    {
        a_bus.ip_next();
        a_bus.move_ip_to(a_bus.get_Instruction(a_bus.get_ip()));
    }
    a_bus.ip_next();
};


m_map[OpCode::JL] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    
    if (top_1 < top_2)
    {
        a_bus.ip_next();
        a_bus.move_ip_to(a_bus.get_Instruction(a_bus.get_ip()));
    }
    a_bus.ip_next();
};


m_map[OpCode::JLE] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    
    if (top_1 <= top_2)
    {
        a_bus.ip_next();
        a_bus.move_ip_to(a_bus.get_Instruction(a_bus.get_ip()));
    }
    a_bus.ip_next();
};


m_map[OpCode::JGI] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    
    if (top_1 > top_2)
    {
        int num = a_bus.pop_from_ip_stack();
        a_bus.move_ip_to(num);
    }
    a_bus.ip_next();
};

m_map[OpCode::JGE] = [&a_bus]()
{
    int top_1 = a_bus.pop_from_stack();
    int top_2 = a_bus.pop_from_stack();
    
    if (top_1 == top_2)
    {
        int num = a_bus.pop_from_ip_stack();
        a_bus.move_ip_to(num);
    }
    a_bus.ip_next();
};


m_map[OpCode::PUSHIP] = [&a_bus]()
{
    a_bus.ip_next();
    
    a_bus.push_to_ip_stack(a_bus.get_Instruction(a_bus.get_ip()));
    
    a_bus.ip_next();
};



}

OpCode Mapper::operator[](int64_t a_opcode)
{
    return static_cast<OpCode>(a_opcode);
}
    
int64_t Mapper::operator[](std::string const& a_opcode)
{
    return static_cast<int64_t>(m_opcode.at(a_opcode));
}
    
func const& Mapper::operator[](OpCode a_opcode)
{
    return m_map.at(a_opcode);
}



/*
auto Mapper::find_instruction(auto a_word)
{
auto instruction_create = m_map.find(a_word);

if(instruction_create == m_map.end())
{
    throw MapError("Map find", "command doesn't exist in map");//TODO
}
*/
//return instruction_create->second();
//}


int64_t Mapper::from_string_to_enum(std::string a_word)
{
    return m_opcode[a_word];
}

