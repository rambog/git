/*======================================================================
*        filename: globalfile.cpp
*        author: rambogui
*        data: 2018-12-18 15:33:26
======================================================================*/

#include <iostream>

int global = 10;

void printglobal()
{
    std::cout << "globalfile global addr: " << &global << std::endl;
}
