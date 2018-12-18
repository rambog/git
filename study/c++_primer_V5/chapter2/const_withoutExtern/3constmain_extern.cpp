/*======================================================================
*        filename: constmain_extern.cpp
*        author: rambogui
*        data: 2018-12-18 15:40:00
======================================================================*/

#include <iostream>

extern int file;

void printfile();

int main(int argc, char *argv[])
{
    file = 10;
    std::cout << "constmain file addr: " << &file << std::endl;
    printfile();
    return 0;
}
