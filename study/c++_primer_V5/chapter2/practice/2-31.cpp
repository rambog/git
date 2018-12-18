/*======================================================================
*        filename: 2-31.cpp
*        author: rambogui
*        data: 2018-12-18 16:30:03
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const int v2 = 0;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = v2, &r2 = v2;

    r1 = v2;
    //p1 = p2;
    p2 = p1;
    p1 = p3;
    p2 = p3;

    return 0;
}
