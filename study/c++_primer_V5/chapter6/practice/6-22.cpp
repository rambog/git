/*======================================================================
*        filename: 6-22.cpp
*        author: rambogui
*        data: 2018-12-21 13:25:36
======================================================================*/

#include <iostream>

void exchage(int **pp1, int **pp2)
{
    int *ptmp;
#if 0
    *pp1 ^= *pp2;
    *pp2 ^= *pp1;
    *pp1 ^= *pp2;
#else
    ptmp = *pp1;
    *pp1 = *pp2;
    *pp2 = ptmp;
#endif
}

int main(int argc, char *argv[])
{
    int i1 = 20, i2 = 10;
    int *p1 = &i1, *p2 = &i2;

    std::cout << p1 << ' ' << p2 << ' ' << *p1 << ' ' << *p2 << std::endl;
    std::cout << i1 << ' ' << i2 << std::endl;
    exchage(&p1, &p2);
    std::cout << p1 << ' ' << p2 << ' ' << *p1 << ' ' << *p2 << std::endl;
    std::cout << i1 << ' ' << i2 << std::endl;

    return 0;
}
