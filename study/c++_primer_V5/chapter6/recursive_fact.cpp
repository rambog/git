/*======================================================================
*        filename: recursive_fact.cpp
*        author: rambogui
*        data: 2018-12-21 14:55:57
======================================================================*/

#include <iostream>

int factorial(int val)
{
    if (val > 1)
        return factorial(val-1)*val;
    return 1;
}

int main(int argc, char *argv[])
{
    std::cout << factorial(5) << std::endl;
    return 0;
}
