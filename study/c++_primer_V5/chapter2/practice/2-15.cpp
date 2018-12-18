/*======================================================================
*        filename: 2-15.cpp
*        author: rambogui
*        data: 2018-12-18 13:44:55
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int ival = 1.01;
    const int &rval1 = 1.01;
    int &rval2 = ival;
    //int &rval3;
    return 0;
}
