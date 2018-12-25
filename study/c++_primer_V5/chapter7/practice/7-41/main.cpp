/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-25 10:39:02
======================================================================*/

#include <iostream>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
    Sales_data d1("rambo", 0, 0);
    std::cout << std::endl;
    Sales_data d2;
    std::cout << std::endl;
    Sales_data d3("guiyao");
    std::cout << std::endl;
    Sales_data d4(std::cin);
    return 0;
}
