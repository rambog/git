/*======================================================================
*        filename: 10-14.cpp
*        author: rambogui
*        data: 2019-01-03 08:49:34
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int (*flambda)(int, int) = [](int i1, int i2) -> int
                                { return i1+i2; };

    int i1, i2;

    if (std::cin >> i1 >> i2)
        std::cout << "sum is: " << flambda(i1, i2) << std::endl;

    return 0;
}
