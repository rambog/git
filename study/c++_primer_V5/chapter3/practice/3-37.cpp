/*======================================================================
*        filename: 3-37.cpp
*        author: rambogui
*        data: 2018-12-19 18:52:14
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        std::cout << *cp << std::endl;
        ++cp;
    }
    return 0;
}
