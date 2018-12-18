/*======================================================================
*        filename: null_pointer.cpp
*        author: rambogui
*        data: 2018-12-18 14:05:47
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    std::cout << "nullptr: " << p1 << std::endl;
    std::cout << "0: " << p2 << std::endl;
    std::cout << "NULL: " << p3 << std::endl;

    return 0;
}
