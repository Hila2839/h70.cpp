#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>



void write_plan_to_file()
{
    std::ofstream file;;
    file.open("plan 1");

    assert(file && "file open filure, need more channel");
    
    file<< "PUSH 18";//0
    file<<'\n';
    file<< "NOP";//0
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
    file<<"IN";//7
    file<<'\n';
    file<<"OUT";//8
    file<<'\n';
    file<<"LOAD";//9
    file<<'\n';
    file<<"DROP";//10
    file<<'\n';
    file<<"STOR";//11
    file<<'\n';
    file<<"JZ";//12
    file<<'\n';
    file<<"DUP";//13
    file<<'\n';
    file<<"SWAP";//14
    file<<'\n';
    file<<"ROL3";//15
    file<<'\n';
    file<<"INNUM";//16
    file<<'\n';
    file<<"OUTNUM";//17
    file<<'\n';
    file<<"JNZ";//18
    file<<'\n';
    file<<"COMPL";//19
    file<<'\n';



    file<<"JMP";
    file<<'\n';






    file<<"HLT";
    file<<'\n';
    

    file.close();

}

int main()
{
    write_plan_to_file();
    return 0;
}

