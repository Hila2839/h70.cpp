#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>



void write_plan_to_file()
{
    std::ofstream file;;
    file.open("plan");

    assert(file && "file open filure, need more channel");
    
    file<<"PUSH 5";//6
    file<<'\n';
    file<<"PUSH 100";//6
    file<<'\n';
    file<<"PUSH 0";//6
    file<<'\n';
    file<<"PUSH 2";//6
    file<<'\n';
    file<<"PUSH 10";//6
    file<<'\n';
    file<<"PUSH 10";//6
    file<<'\n';
    file<<"PUSH 10";//6
    file<<'\n';
    file<<"PUSH 10";//6
    file<<'\n';
    file<<"PUSH 10";//6
    file<<'\n';
    file<<"PUSH 10";//6
    file<<'\n';
    file<<"PUSH 5";//6
    file<<'\n';
    file<<"ADD";//1
    file<<'\n';
    file<<"SUB";//2
    file<<'\n';
    file<<"AND";//3
    file<<'\n';
    file<<"OR";//4
    file<<'\n';
    file<<"XOR";//5
    file<<'\n';
    file<<"NOT";//6
    file<<'\n';
    file<<"NOP";//6
    file<<'\n';


    file<<"HLT";//6
    file<<'\n';
    

    file.close();

}

int main()
{
    write_plan_to_file();
    return 0;
}

