/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-25 11:16:40
======================================================================*/

#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
    Sales_data s;
    s = Sales_data(std::cin);

    Sales_data s2;
    s2 = std::string("rambo");

    return 0;
}
