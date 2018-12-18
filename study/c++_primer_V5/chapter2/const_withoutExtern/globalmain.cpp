/*======================================================================
*        filename: globalmain.cpp
*        author: rambogui
*        data: 2018-12-18 15:33:26
======================================================================*/

#include <iostream>

int global = 10;

void printglobal();

int main(int argc, char *argv[])
{
    std::cout << "globalmain global addr: " << &global << std::endl;
    printglobal();
    
    return 0;
}
