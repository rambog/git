/*======================================================================
*        filename: reftopointer.cpp
*        author: rambogui
*        data: 2018-12-18 14:49:23
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int *p;
    int *&r = p, i = 42;

    r = &i;

    std::cout << *r << std::endl;
    *r = 0;
    std::cout << i << std::endl;

    std::cout << p << ' ' << r << std::endl;
    std::cout << &p << ' ' << &r << std::endl;

    return 0;
}
