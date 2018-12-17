/*======================================================================
*        filename: 1-6.cpp
*        author: rambogui
*        data: 2018-12-17 11:31:19
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int v1 = 11, v2 = 13;
#if 0
    std::cout << "The sum of " << v1;
              << " and " << v2;
              << " is " << v1 + v2 << std::endl;
#else
    std::cout << "The sum of " << v1;
    std::cout << " and " << v2;
    std::cout << " is " << v1 + v2 << std::endl;
#endif
    return 0;
}
