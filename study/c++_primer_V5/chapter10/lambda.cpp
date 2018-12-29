/*======================================================================
*        filename: lambda.cpp
*        author: rambogui
*        data: 2018-12-29 14:30:50
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int (*f)() = [] { return 42; };

    std::cout << f() << std::endl;
    return 0;
}
