/*======================================================================
*        filename: constexpr_func.cpp
*        author: rambogui
*        data: 2018-12-22 09:25:26
======================================================================*/

#include <iostream>

constexpr int foo(int i) { return 2*i; }

int main(int argc, char *argv[])
{
    int i;
    const int ci = i;
    constexpr int cci = foo(i);
    return 0;
}
