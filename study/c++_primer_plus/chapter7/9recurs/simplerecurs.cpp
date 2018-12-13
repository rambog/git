/*======================================================================
*        filename: simplerecurs.cpp
*        author: rambogui
*        data: 2018-11-29 17:18:30
======================================================================*/

#include <iostream>

void foo();

int main(int argc, char *argv[])
{
    foo();
    return 0;
}

void foo()
{
    int tmp[1024];
    foo();
}
