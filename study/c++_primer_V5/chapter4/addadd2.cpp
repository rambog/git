/*======================================================================
*        filename: addadd2.cpp
*        author: rambogui
*        data: 2018-12-20 14:44:05
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 1;
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;

    std::cout << i++ << ' ' << i << std::endl;
    std::cout << *++p << ' ' << *p << std::endl;

    return 0;
}
