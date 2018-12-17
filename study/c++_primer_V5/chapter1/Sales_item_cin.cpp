/*======================================================================
*        filename: Sales_item_cin.cpp
*        author: rambogui
*        data: 2018-12-17 17:13:08
======================================================================*/

#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[])
{
    Sales_item total;

    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.Isbn() == trans.Isbn())
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
