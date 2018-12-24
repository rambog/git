/*======================================================================
*        filename: funcrettype.cpp
*        author: rambogui
*        data: 2018-12-22 09:33:17
======================================================================*/

#include <iostream>

void foo();

int main(int argc, char *argv[])
{
    foo();
    
    return 0;
}

int foo()
{
    std::cout << "foo" << std::endl;
    return 1;
}
