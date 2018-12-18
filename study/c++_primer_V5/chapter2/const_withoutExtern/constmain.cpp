/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-18 15:30:05
======================================================================*/

#include <iostream>

const int file = 5;

void printfile();

int main(int argc, char *argv[])
{
    std::cout << "main.cpp file addr: " << &file << std::endl;
    printfile();
    return 0;
}
