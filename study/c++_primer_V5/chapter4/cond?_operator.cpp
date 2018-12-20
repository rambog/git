/*======================================================================
*        filename: cond?_operator.cpp
*        author: rambogui
*        data: 2018-12-20 13:43:45
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 10;
    int i2 = 10;
    
    (1?i:i) = 13;

    std::cout << i << std::endl;

    return 0;
}
