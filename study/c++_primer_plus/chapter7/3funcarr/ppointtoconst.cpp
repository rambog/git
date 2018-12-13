/*======================================================================
*        filename: ppointtoconst.cpp
*        author: rambogui
*        data: 2018-11-29 14:48:18
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const int **pp2;
    const int *p1;
    const int *p2;
    int tmp;

    p1 = &tmp;
    pp2 = &p1;
    pp2 = &p2;

    *pp2 = &tmp;
    **pp2 = 10;

    return 0;
}
