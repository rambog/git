/*======================================================================
*        filename: defpara_overload.cpp
*        author: rambogui
*        data: 2018-12-22 09:07:34
======================================================================*/

#include <iostream>

void foo(int);
void foo(int, int=1);

int main(int argc, char *argv[])
{
    foo(1.5);
    return 0;
}

void foo(int i)
{
    std::cout << "only one para\n";
}

void foo(int i1, int i2)
{
    std::cout << "two para\n";
}
