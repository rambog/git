/*======================================================================
*        filename: 4-9.cpp
*        author: rambogui
*        data: 2018-12-20 11:25:20
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const char *cp = "Hello World";
    if (cp && *cp)
        std::cout << cp << ' ' << (void*)cp << ' ' << *cp << std::endl;
    return 0;
}
