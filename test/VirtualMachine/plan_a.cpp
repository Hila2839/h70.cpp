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
    file<<"NOP";
    

    file.close();

}

int main()
{
    write_plan_to_file();
    return 0;
}

