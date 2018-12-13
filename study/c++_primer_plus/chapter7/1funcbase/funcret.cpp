/*======================================================================
*        filename: funcret.cpp
*        author: rambogui
*        data: 2018-11-29 08:14:54
======================================================================*/

#include <iostream>

int foo();

int main(int argc, char *argv[])
{
    using namespace std;

    int *pt = &(foo()); 

    return 0;
}

int foo()
{
    int tmp = 10;
    return tmp;
}
