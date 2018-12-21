/*======================================================================
*        filename: fact.cpp
*        author: rambogui
*        data: 2018-12-21 08:32:13
======================================================================*/

#include <iostream>

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int main(int argc, char *argv[])
{
    int j = fact(5);
    std::cout << "5! is " << j << std::endl;
    return 0;
}
