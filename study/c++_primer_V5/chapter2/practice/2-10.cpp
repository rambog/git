/*======================================================================
*        filename: 2-10.cpp
*        author: rambogui
*        data: 2018-12-18 10:42:03
======================================================================*/

#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main(int argc, char *argv[])
{
    int local_int;
    std::string local_str;

    std::cout << "global: " << global_int << ' ' << global_str << std::endl;
    std::cout << "local: " << local_int << ' ' << local_str << std::endl;

    return 0;
}
