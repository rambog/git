/*======================================================================
*        filename: typeup.cpp
*        author: rambogui
*        data: 2018-12-22 10:08:36
======================================================================*/

#include <iostream>

void foo(int i)
{
    std::cout << "foo(int)" << std::endl;
}

void foo(short s)
{
    std::cout << "foo(short)" << std::endl;
}

void foo(double d)
{
    std::cout << "foo(double)" << std::endl;
}

int main(int argc, char *argv[])
{
    unsigned char tmp;

    foo(tmp);

    return 0;
}
