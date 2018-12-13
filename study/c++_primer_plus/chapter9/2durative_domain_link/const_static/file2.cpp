/*======================================================================
*        filename: file2.cpp
*        author: rambogui
*        data: 2018-12-03 14:58:17
======================================================================*/

#include <iostream>
#include "foo.h"

void foo();

int main(int argc, char *argv[])
{
    std::cout << "in main " << &foocnst << std::endl;

    foo();
    return 0;
}
