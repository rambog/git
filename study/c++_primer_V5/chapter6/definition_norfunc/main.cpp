/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-22 09:13:50
======================================================================*/

#include <iostream>

double foo(int);

int main(int argc, char *argv[])
{
    int i;
    double d = foo(1);
    std::cout << d << std::endl;
    return 0;
}
