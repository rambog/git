/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-24 11:13:55
======================================================================*/

#include <iostream>
#include "screen.h"

int main(int argc, char *argv[])
{
    Screen myScreen(5, 5, 'X');    
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << std::endl;

    myScreen.display(std::cout);
    std::cout << "\n";
    return 0;
}
