#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>



void write_plan_to_file()
{
    std::ofstream file;;
    file.open("loop");

    assert(file && "file open filure, need more channel");
    

    file<< "PUSH 100";//0
    file<<'\n';
    file<< "PUSHIP 5";//0
    file<<'\n';
    file<<"PUSHIP 13";//1
    file<<'\n';
    file<<"POPIP";//2
    file<<'\n';
    file<<"ADD";//3
    file<<'\n';
    file<<"HLT";//4
    file<<'\n';
    file<<"NOP";//5
    file<<'\n';
    file<<"NOP";//6
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"ADD";//7
    file<<'\n';
    file<<"ADD";//7
    file<<'\n';
    file<<"ADD";//7
    file<<'\n';
    file<<"ADD";//7
    file<<'\n';
    file<<"ADD";//7
    file<<'\n';
    file<<"POPIP";//8
    file<<'\n';
    file<<"HLT";//9
    file<<'\n';
    
    

    file.close();

}

int main()
{
    write_plan_to_file();
    return 0;
}

