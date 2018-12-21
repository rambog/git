/*======================================================================
*        filename: 6-10.cpp
*        author: rambogui
*        data: 2018-12-21 09:35:08
======================================================================*/

#include <iostream>

void exchange(int *p1, int *p2)
{
#if 0
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
#else
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
#endif
}

int main(int argc, char *argv[])
{
    int i1, i2;

    while (std::cin >> i1 >> i2) {
        std::cout << i1 << ' ' << i2 << std::endl;
        exchange(&i1, &i2);
        std::cout << i1 << ' ' << i2 << std::endl;
    }

    return 0;
}
