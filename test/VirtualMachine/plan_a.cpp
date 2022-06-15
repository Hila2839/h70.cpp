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
    
    file<< "NOP";
    file<<'\n';
    file<<"ADD";
    file<<'\n';
    file<<"SUB";
    file<<'\n';
    file<<"AND";
    file<<'\n';
    file<<"OR";
    file<<'\n';
    file<<"XOR";
    file<<'\n';
    file<<"NOT";
    file<<'\n';
    file<<"IN";
    file<<'\n';
    file<<"OUT";
    file<<'\n';
    //file<<"LOAD";
    //file<<'\n';
    file<<"DROP";
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

