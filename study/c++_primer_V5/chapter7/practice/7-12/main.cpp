/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-24 08:46:35
======================================================================*/

#include <iostream>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
    Sales_data s1(std::cin);
    print(std::cout, s1) << std::endl;
    return 0;
}
