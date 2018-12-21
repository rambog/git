/*======================================================================
*        filename: 6-12_ref.cpp
*        author: rambogui
*        data: 2018-12-21 10:02:05
======================================================================*/

#include <iostream>

void exchange(int &p1, int &p2)
{
    p1 ^= p2;
    p2 ^= p1;
    p1 ^= p2;
}

int main(int argc, char *argv[])
{
    int p1, p2;

    while (std::cin >> p1 >> p2) {
        exchange(p1, p2);
        std::cout << p1 << ' ' << p2 << std::endl;
    }

    return 0;
}
