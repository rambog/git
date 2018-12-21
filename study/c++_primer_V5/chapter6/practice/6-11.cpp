/*======================================================================
*        filename: 6-11.cpp
*        author: rambogui
*        data: 2018-12-21 10:00:29
======================================================================*/

#include <iostream>

void reset(int &val)
{
    val = 0;
}

int main(int argc, char *argv[])
{
    int i = 10;

    std::cout << i << std::endl;
    reset(i);
    std::cout << i << std::endl;

    return 0;
}
