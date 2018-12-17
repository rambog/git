/*======================================================================
*        filename: Sales_item_add.cpp
*        author: rambogui
*        data: 2018-12-17 15:48:07
======================================================================*/

#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    return 0;
}
