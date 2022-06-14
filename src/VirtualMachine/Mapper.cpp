#include "Mapper.hpp"
#include "NOP.hpp"





Mapper::Mapper()
: m_map()
{
m_map[NOP::NAME] = &create_nop;

}


Instruction* Mapper::find_instruction(std::string const& a_word, Ip& a_ip,Memory& a_memory,Stack& a_stack)
{
std::map<std::string,funcPointer>::iterator instruction_create;
instruction_create = m_map.find(a_word);
/*
if(instruction_create == m_map.end())
{
    throw MapError("Map find", "command doesn't exist in map");//TODO
}

catch(MapError const& a_error)
{
    cout<<"command doesn't exist in map\n";
}*/

return instruction_create->second(a_ip, a_memory, a_stack);
}

