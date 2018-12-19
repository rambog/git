/*======================================================================
*        filename: 3-38.cpp
*        author: rambogui
*        data: 2018-12-19 18:53:54
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 10;
    int *pi1 = &i;
    int *pi2 = &i;

    pi1+pi2;

    return 0;
}
