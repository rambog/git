/*======================================================================
*        filename: testmain.cpp
*        author: rambogui
*        data: 2019-01-16 17:12:06
======================================================================*/

#include <iostream>
#include "dullinklist.h"

int main(int argc, char *argv[])
{
    dullinklist *dl = new dullinklist({1,2,3,4,5,6,7,8,9});
    dullinklist dl1(*dl);
    dullinklist dl2;
    dl2 = *dl;

    std::cout << *dl << std::endl;
    std::cout << dl->length() << std::endl;
    std::cout << dl1 << std::endl;
    std::cout << dl1.length() << std::endl;
    std::cout << dl2 << std::endl;
    std::cout << dl2.length() << std::endl;

    delete dl;    

    std::cout << std::endl;
    std::cout << dl1 << std::endl;
    std::cout << dl2 << std::endl;
    std::cout << *dl << std::endl;
    return 0;
}
