/*======================================================================
*        filename: 6-50.cpp
*        author: rambogui
*        data: 2018-12-22 09:52:09
======================================================================*/

#include <iostream>

void f()
{
    std::cout << "f()" << std::endl;
}

void f(int i)
{
    std::cout << "f(int)" << std::endl;
}

void f(int i1, int i2)
{
    std::cout << "f(int, int)" << std::endl;
}

void f(double d1, double d2 = 3.14)
{
    std::cout << "f(double, double" << std::endl;
}

int main(int argc, char *argv[])
{
    f(2.56, 42);
    f(42);
    f(42,0);
    f(2.56, 3.14);
    return 0;
}
