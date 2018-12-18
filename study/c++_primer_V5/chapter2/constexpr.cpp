/*======================================================================
*        filename: constexpr.cpp
*        author: rambogui
*        data: 2018-12-18 16:57:55
======================================================================*/

#include <iostream>

int read()
{
    return 100;
}

int main(int argc, char *argv[])
{
    constexpr int i = read();
    const int i2 = read();
    return 0;
}
