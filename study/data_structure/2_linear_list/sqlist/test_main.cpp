/*======================================================================
*        filename: test_main.cpp
*        author: rambogui
*        data: 2019-01-15 10:58:24
======================================================================*/

#include <iostream>
#include "sqlist.h"

int main(int argc, char *argv[])
{
    sqlist la({1,2,3,4,5,6,7,8,9,10,11,12});
    std::cout << la << std::endl;
    
    la.insert(0, 100);
    la.insert(3, 99);
    la.insert(9, 9001);

    std::cout << la << std::endl;

    ElemType tmp;
    la.del(10, tmp);
    std::cout << la << std::endl;
    std::cout << tmp << std::endl;

    la.insert(la.length(), 88);
    la.insert(la.length(), 8888);
    std::cout << la << std::endl;

    return 0;
}
