/*======================================================================
*        filename: globaldefi_localdecl.cpp
*        author: rambogui
*        data: 2018-12-22 09:34:52
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int foo();
    std::cout << foo() << std::endl;

    //int foo() { return 2; }

    return 0;
}

int foo()
{
    return 1;
}
