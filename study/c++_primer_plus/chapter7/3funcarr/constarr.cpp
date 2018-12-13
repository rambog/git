/*======================================================================
*        filename: constarr.cpp
*        author: rambogui
*        data: 2018-11-29 14:56:59
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const int months[12] = {31,28,31,30};

    months[3] = 100;

    return 0;
}
