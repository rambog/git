/*======================================================================
*        filename: 10-15.cpp
*        author: rambogui
*        data: 2019-01-03 08:55:24
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i1, i2;
    if (std::cin >> i1 >> i2)
        ;
    else 
        return 0;

    auto f = [i1](int i2) -> int
                { return i1+i2; };

    std::cout << "sum is: " << f(i2) << std::endl;

    return 0;
}
