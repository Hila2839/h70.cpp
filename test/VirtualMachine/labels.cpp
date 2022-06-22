#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>



void write_plan_to_file()
{
    std::ofstream file;;
    file.open("labels");

    assert(file && "file open filure, need more channel");
 
    file<< "PUSH 100";//0
    file<<'\n';
    file<< "PUSHIP L12";//1
    file<<'\n';
    file<<"PUSHIP MUL_6";//2
    file<<'\n';
    file<<"POPIP";//3
    file<<'\n';
    file<<"L12:";//3
    file<<'\n';
    file<<"PUSH 12";//4
    file<<'\n';
    file<<"PUSHIP SUM";//5
    file<<'\n';
    file<<"PUSHIP MUL_6";//6
    file<<'\n';
    file<<"POPIP";//7
    file<<'\n';
    file<<"SUM:";//3
    file<<'\n';
    file<<"ADD";//8
    file<<'\n';
    file<<"HLT";//9
    file<<'\n';
    file<<"MUL_6:";//10
    file<<'\n';
    file<<"DUP";//12
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"DUP";//14
    file<<'\n';
    file<<"DUP";//15
    file<<'\n';
    file<<"DUP";//16
    file<<'\n';
    file<<"POPIP";//22
    file<<'\n';
    file<<"ADD";//17
    file<<'\n';
    file<<"ADD";//18
    file<<'\n';
    file<<"ADD";//19
    file<<'\n';
    file<<"ADD";//20
    file<<'\n';
    file<<"ADD";//21
    file<<'\n';
    file<<"POPIP";//21
    file<<'\n';
    file<<"HLT";//23
    file<<'\n';
    
    

    file.close();

}

int main()
{
    write_plan_to_file();
    return 0;
}

