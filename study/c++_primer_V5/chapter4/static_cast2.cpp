/*======================================================================
*        filename: static_cast2.cpp
*        author: rambogui
*        data: 2018-12-20 16:18:56
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const char *cp;

    //char *q = static_cast<char*>(cp);
    char *p = const_cast<char*>(cp);

    return 0;
}
