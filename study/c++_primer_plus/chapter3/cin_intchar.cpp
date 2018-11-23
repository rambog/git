/*======================================================================
*        filename: cin_intchar.cpp
*        author: rambogui
*        data: 2018-11-23 11:17:24
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int inttmp = 'A';
    char chartmp = 'A';

    std::cin >> inttmp >> chartmp;

    std::cout << (int)inttmp << " " << (int)chartmp << std::endl;

    return 0;
}
