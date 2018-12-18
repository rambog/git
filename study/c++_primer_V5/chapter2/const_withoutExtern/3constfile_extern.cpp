/*======================================================================
*        filename: constfile_extern.cpp
*        author: rambogui
*        data: 2018-12-18 15:40:00
======================================================================*/

#include <iostream>

extern const int file = 10;

void printfile()
{
    std::cout << "constfile file addr: " << &file << std::endl;
}
