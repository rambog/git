/*======================================================================
*        filename: newplace2.cpp
*        author: rambogui
*        data: 2018-12-03 17:31:18
======================================================================*/

#include <iostream>
#include <new>

const int SIZE = 119;

int *foo()
{
    int buff[120];
    int *p = new(buff) int[SIZE];
    std::cout << buff << ' ' << p << std::endl;
    return p;
}

void foo2(int *p)
{
    for (int i = 0; i < SIZE; i++)
        p[i] = 0x00ff0f0f;
    int *tmp = foo();
    for (int i = 0; i < SIZE; i++)
        tmp[i] = 0x00ff0f0f;
}

int main(int argc, char *argv[])
{
    std::cout << &SIZE << std::endl;
    int *ptmp = foo();
    for (int i = 0; i < SIZE; i++)
        ptmp[i] = 0xff903289;
    foo2(foo());

    return 0;
}
