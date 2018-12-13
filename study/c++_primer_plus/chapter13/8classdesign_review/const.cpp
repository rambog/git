/*======================================================================
*        filename: const.cpp
*        author: rambogui
*        data: 2018-12-13 11:21:21
======================================================================*/

#include <iostream>

void foo1(int &f)
{
}

void foo2(const int &f)
{
    foo1(f);
}

int main(int argc, char *argv[])
{
    const int tmp = 8;

    foo2(tmp);

    return 0;
}
