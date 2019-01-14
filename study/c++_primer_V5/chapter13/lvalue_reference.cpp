/*======================================================================
*        filename: lvalue_reference.cpp
*        author: rambogui
*        data: 2019-01-08 15:42:32
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    int &r1 = i;
    int &r2 = r1;
    return 0;
}
