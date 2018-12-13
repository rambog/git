/*======================================================================
*        filename: foo2.cpp
*        author: rambogui
*        data: 2018-12-03 16:29:47
======================================================================*/

#include <iostream>

int foo();

int foo2()
{
    foo();
    std::cout << "foo2 call : " << (void*)foo << std::endl;
    return 0;
}
