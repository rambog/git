/*======================================================================
*        filename: rvalue_reference.cpp
*        author: rambogui
*        data: 2019-01-08 15:40:31
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int &&rr1 = 42;
    int &&rr2 = rr1;
    std::cout << rr1 << std::endl;
    std::cout << &rr1 << std::endl;
    return 0;
}
