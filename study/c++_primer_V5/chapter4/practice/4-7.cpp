/*======================================================================
*        filename: 4.7.cpp
*        author: rambogui
*        data: 2018-12-20 10:49:17
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int temp;

    temp = 0x7fffffff;
    std::cout << temp << ' ' << temp+1 << std::endl;

    temp = 0x80000000;
    std::cout << temp << ' ' << temp-1 << std::endl;

    temp = 0x80000000;
    std::cout << temp << ' ' << temp - -1 << std::endl;

    int i = 0xffffffff;
    temp =  0x80000000;
    std::cout << i << ' ' << temp+i << std::endl;
        
    return 0;
}
