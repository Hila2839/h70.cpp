#include "Mapper.hpp"
#include "Nop.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Xor.hpp"
#include "Not.hpp"
#include "In.hpp"
#include "Out.hpp"
#include "Load.hpp"
#include "Hlt.hpp"
#include "Drop.hpp"
#include "Stor.hpp"
#include "Jmp.hpp"
#include "Jz.hpp"
#include "Dup.hpp"
#include "Swap.hpp"
#include "Rol3.hpp"
#include "Outnum.hpp"
#include "Innum.hpp"
#include "Jnz.hpp"
#include "Push.hpp"
#include "Compl.hpp"











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
m_map[STOR::NAME] = &create_stor;
m_map[JMP::NAME] = &create_jmp;
m_map[JZ::NAME] = &create_jz;
m_map[DUP::NAME] = &create_dup;
m_map[SWAP::NAME] = &create_swap;
m_map[ROL3::NAME] = &create_rol3;
m_map[OUTNUM::NAME] = &create_outnum;
m_map[INNUM::NAME] = &create_innum;
m_map[JNZ::NAME] = &create_jnz;
m_map[PUSH::NAME] = &create_nop;
m_map[COMPL::NAME] = &create_compl;





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
*/
return instruction_create->second(a_ip, a_memory, a_stack);
}

