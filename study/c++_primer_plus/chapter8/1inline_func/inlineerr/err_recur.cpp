/*======================================================================
*        filename: err_recur.cpp
*        author: rambogui
*        data: 2018-11-30 10:01:07
======================================================================*/

#include <iostream>

inline void foo(int);

int main(int argc, char *argv[])
{
    foo(0);
    return 0;
}

inline void foo(int n)
{
    //if (n == 0) return;

    foo(n-1);
}
