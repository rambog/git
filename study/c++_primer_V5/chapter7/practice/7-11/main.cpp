/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-24 08:38:04
======================================================================*/

#include <iostream>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
    Sales_data s1;
    print(std::cout, s1) << std::endl;

    Sales_data s2("rambo");
    print(std::cout, s2) << std::endl;

    Sales_data s3("guiyao", 10, 12.9);
    print(std::cout, s3) << std::endl;
    
    Sales_data s4(std::cin);
    print(std::cout, s4) << std::endl;
    return 0;
}
