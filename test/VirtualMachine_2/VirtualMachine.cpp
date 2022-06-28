#include <string>
#include "vector"


#include "VirtualMachine.hpp"
#include "Memory.hpp"
#include "Loader.hpp"
#include "MachineError.hpp"
#include "Bus.hpp"
#include "Mapper.hpp"



VirtualMachine::VirtualMachine(size_t a_stack_size, size_t a_data_memory_size, size_t a_orders_memory_size, const char* a_file_name)
: m_stack(a_stack_size)
, m_ip()
, m_memory(a_data_memory_size, a_orders_memory_size)
, m_file_name(a_file_name)
, m_ip_stack(a_stack_size)
{
    Loader load(m_file_name);
   
    std::vector<int64_t> memory = load.memory_create();
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


Stack& VirtualMachine::get_ip_stack()
{
    return m_ip_stack;
}



void VirtualMachine::init_memory()
{
   
}

void VirtualMachine::run()
{
    Bus bus(get_stack(), get_ip(),get_memory(), get_ip_stack());
    m_stack.print();
    std::cout<<"ip stack:\n";
    m_ip_stack.print();
    std::cout<<'\n';
    Mapper map(bus);
    std::cout<<"orders:\n";
    m_memory.print_orders();

    while(true)
    {
        std::cout<<m_ip.get_ip()<<"<-ip :\n";
        try{
        OpCode opcode = static_cast<OpCode>(map[m_memory.get_Instruction(m_ip.get_ip())]);
        map[opcode]();
        std::cout<<"stack:\n";
        m_stack.print();
        std::cout<<'\n';
        std::cout<<"ip stack:\n";
        m_ip_stack.print();
        }
        catch(MachineError& e){
            std::cout<<e<<'\n';
            break;
        }
        catch(...){
            break;
        }
        std::cout<<'\n';
        //catches!!!
        

    }

}


/*
catch(FileError const& a_error)
{
    cout<<"file open error\n";
}*/



int main()
{
    VirtualMachine my_machine(100, 100, 100,"plan");



    my_machine.run();

    return 0;
}