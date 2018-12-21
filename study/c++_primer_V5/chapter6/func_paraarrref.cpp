/*======================================================================
*        filename: func_paraarrref.cpp
*        author: rambogui
*        data: 2018-12-21 11:24:40
======================================================================*/

#include <iostream>

void paraarrref(int (&a)[10])
{
}


int main(int argc, char *argv[])
{
    int a[10];
    paraarrref(a);
    return 0;
}
