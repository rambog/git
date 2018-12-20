/*======================================================================
*        filename: addadd_operator.cpp
*        author: rambogui
*        data: 2018-12-20 13:23:52
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    int temp;

    std::cout << &i << std::endl;
    //std::cout << &(++i) << std::endl;
    //std::cout << &(i++) << std::endl;
    
    decltype(++i) i1 = temp;
    decltype(i++) i2;
    std::cout << i << std::endl;

    return 0;
}
