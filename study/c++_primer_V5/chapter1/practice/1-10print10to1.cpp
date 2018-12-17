/*======================================================================
*        filename: 1-10print10to1.cpp
*        author: rambogui
*        data: 2018-12-17 13:38:39
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int val = 10;
    while (val >= 0) {
        std::cout << val << ' ';
        --val;
    }

    std::cout << std::endl;

    return 0;
}
