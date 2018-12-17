/*======================================================================
*        filename: Sales_item_isbnfunc.cpp
*        author: rambogui
*        data: 2018-12-17 15:55:50
======================================================================*/

#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (item1.Isbn() == item2.Isbn()) {
        std::cout << item1 + item2 << std::endl;
        return 0;
    } else
        std::cerr << "Data must refer to same ISBN" << std::endl;
    return -1;
}
