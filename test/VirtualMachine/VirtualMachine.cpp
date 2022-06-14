#include <string>
#include "vector"


#include "VirtualMachine.hpp"
#include "Memory.hpp"
#include "Loader.hpp"


VirtualMachine::VirtualMachine(size_t a_memory_size,const char* a_file_name)
: m_stack()
, m_ip()
, m_memory(a_memory_size)
, m_file_name(a_file_name)
{
    Loader load(m_file_name);
   
    std::vector<Instruction*> memory = load.memory_create(get_ip(),get_memory(),get_stack());
    m_memory.set_orders_to_memory(memory);

}


Ip& VirtualMachine::get_ip()
{
    return m_ip;
}

Memory& VirtualMachine::get_memory()
{
    return m_memory;
}

void VirtualMachine::set_memory(Memory& a_memory)
{
    m_memory = a_memory;
}

Stack& VirtualMachine::get_stack()
{
    return m_stack;
}

void VirtualMachine::init_memory()
{
   
}

void VirtualMachine::run()
{
    Ip ip;
    while(true)
    {
        m_memory.get_Instruction(ip.get_ip())->execute();
        if(m_memory.get_Instruction(ip.get_ip()) == 0)
        {
            break;
        }
        
        //catches!!!

    }

}






int main()
{
    VirtualMachine my_machine(50 ,"plan 1");
    my_machine.run();

    return 0;
}