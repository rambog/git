/*======================================================================
*        filename: test.cpp
*        author: rambogui
*        data: 2018-11-28 10:56:37
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    false ? i++ : j++;

    std::cout << i << " " << j << std::endl;

    return 0;
}
