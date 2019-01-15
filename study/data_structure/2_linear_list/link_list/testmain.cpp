/*======================================================================
*        filename: testmain.cpp
*        author: rambogui
*        data: 2019-01-15 15:32:52
======================================================================*/

#include <iostream>
#include "linklist.h"

int main(int argc, char *argv[])
{
    linklist la({1,2,3,4,5,6,7,8,9,10});
    std::cout << la << std::endl;
    la.insert(0,-1);
    la.insert(la.length(), 11);
    std::cout << la << std::endl;

    ElemType tmp(3);
    std::cout << la.locate_elem(tmp) << std::endl;

    la.del(0, tmp);
    std::cout << tmp << std::endl;
    la.del(la.length()-1, tmp);
    std::cout << tmp << std::endl;
    la.del(5, tmp);
    std::cout << tmp << std::endl;
    std::cout << la << std::endl;

    return 0;
}
