#include <string>
#include "vector"


#include "VirtualMachine.hpp"
#include "Memory.hpp"
#include "Loader.hpp"


VirtualMachine::VirtualMachine(size_t a_stack_size, size_t a_data_memory_size, size_t a_orders_memory_size, const char* a_file_name)
: m_stack(a_stack_size)
, m_ip()
, m_memory(a_data_memory_size, a_orders_memory_size)
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
    m_stack.print();
    std::cout<<'\n';
    while(true)
    {
        if(m_memory.get_Instruction(m_ip.get_ip()) == 0)
        {
            break;
        }
        std::cout<<m_ip.get_ip()<<"<-ip :";
        //try{
        m_memory.get_Instruction(m_ip.get_ip())->execute();
        m_stack.print();
        //}catch{(MachineError& e)
        //    std::cout << e << '\n';
         //   break;
        //}
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
    VirtualMachine my_machine(100, 100, 100,"plan 1");
    my_machine.get_stack().push(10);
    my_machine.get_stack().push(20);
    my_machine.get_stack().push(5);
    my_machine.get_stack().push(0);
    my_machine.get_stack().push(5);
    my_machine.get_stack().push(2);
    my_machine.get_stack().push(6);
    my_machine.get_stack().push(5);
    my_machine.get_stack().push(2);
    my_machine.get_stack().push(6);

    my_machine.run();

    return 0;
}