/*======================================================================
*        filename: inline2.cpp
*        author: rambogui
*        data: 2018-12-22 09:17:11
======================================================================*/

#include <iostream>

inline int foo();

void inline2()
{
    std::cout << "inline" << foo() << std::endl;
}

inline int foo()
{
    return 2;
}
