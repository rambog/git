/*======================================================================
*        filename: decltype_lr_value.cpp
*        author: rambogui
*        data: 2018-12-20 10:16:34
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    decltype(8+9) i = 10;
    decltype(i+=1) i2 = i;
    std::cout << sizeof i << std::endl;
    std::cout << sizeof i2 << ' ' << i2 << std::endl;
    std::cout << &i2 << ' ' << &i << std::endl;
    return 0;
}
