/*======================================================================
*        filename: 2-20.cpp
*        author: rambogui
*        data: 2018-12-18 14:27:57
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;

    std::cout << i << ' ' << *p1 << std::endl;

    return 0;
}
