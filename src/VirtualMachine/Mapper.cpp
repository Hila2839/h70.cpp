#include "Mapper.hpp"
#include "NOP.hpp"
#include "ADD.hpp"
#include "SUB.hpp"
#include "AND.hpp"
#include "OR.hpp"
#include "XOR.hpp"
#include "NOT.hpp"
#include "IN.hpp"
#include "OUT.hpp"
#include "LOAD.hpp"
#include "HLT.hpp"
#include "DROP.hpp"





Mapper::Mapper()
: m_map()
{
m_map[NOP::NAME] = &create_nop;
m_map[ADD::NAME] = &create_add;
m_map[SUB::NAME] = &create_sub;
m_map[AND::NAME] = &create_and;
m_map[OR::NAME] = &create_or;
m_map[XOR::NAME] = &create_xor;
m_map[NOT::NAME] = &create_not;
m_map[IN::NAME] = &create_in;
m_map[OUT::NAME] = &create_out;
m_map[LOAD::NAME] = &create_load;
m_map[HLT::NAME] = &create_hlt;
m_map[DROP::NAME] = &create_drop;

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

