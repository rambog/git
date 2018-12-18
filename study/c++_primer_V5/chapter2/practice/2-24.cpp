/*======================================================================
*        filename: 2-24.cpp
*        author: rambogui
*        data: 2018-12-18 14:36:37
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 42;
    void *p = &i;
    long *lp = (long*)&i;

    std::cout << i << ' ' << *lp << std::endl;

    return 0;
}
