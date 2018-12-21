/*======================================================================
*        filename: constpointer.cpp
*        author: rambogui
*        data: 2018-12-21 10:41:57
======================================================================*/

#include <iostream>

void foo(/*const*/ int* p)
{
    std::cout << *p << std::endl;
}

int main(int argc, char *argv[])
{
    const int i = 10;
    foo(&i);
    return 0;
}
