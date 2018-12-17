/*======================================================================
*        filename: 1-10forpinrt10to1.cpp
*        author: rambogui
*        data: 2018-12-17 13:59:15
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int val = 0;

    for (val = 10; val >= 0; --val)
        std::cout << val << ' ';
    std::cout << std::endl;

    return 0;
}
