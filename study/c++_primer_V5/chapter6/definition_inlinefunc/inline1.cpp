/*======================================================================
*        filename: inline1.cpp
*        author: rambogui
*        data: 2018-12-22 09:17:11
======================================================================*/

#include <iostream>

inline int foo();

void inline1()
{
    std::cout << "inline" << foo() << std::endl;
}

inline int foo()
{
    return 1;
}

