/*======================================================================
*        filename: 4-27.cpp
*        author: rambogui
*        data: 2018-12-20 14:51:19
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    unsigned long ul1 = 3, ul2 = 7;

    std::cout << (ul1 & ul2) << std::endl;
    std::cout << (ul1 | ul2) << std::endl;
    std::cout << (ul1 && ul2) << std::endl;
    std::cout << (ul1 || ul2) << std::endl;
    std::cout << std::endl;
    std::cout << sizeof(ul1&ul2) << std::endl;

    return 0;
}
