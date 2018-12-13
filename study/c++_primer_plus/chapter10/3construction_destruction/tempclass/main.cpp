/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-06 08:28:10
======================================================================*/

#include <iostream>
#include "classfoo.h"

int main(int argc, char *argv[])
{
    foo f1;
    foo f2 = foo("rambo");
    foo f3 = foo();

    f3 = foo("guiyao");
    
    std::cout << sizeof f1 << std::endl;

    return 0;
}
