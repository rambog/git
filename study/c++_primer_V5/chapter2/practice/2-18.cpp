/*======================================================================
*        filename: 2-18.cpp
*        author: rambogui
*        data: 2018-12-18 14:24:28
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i1 = 100;
    int i2 = 101;

    int *pi = &i2;

    std::cout << &i1 << ' ' << &i2 << std::endl;
    std::cout << *pi << ' ' << *(pi+1) << std::endl;

    return 0;
}
