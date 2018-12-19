/*======================================================================
*        filename: struct.cpp
*        author: rambogui
*        data: 2018-12-19 08:06:57
======================================================================*/

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, char *argv[])
{
    std::cout << sizeof(Sales_data) << std::endl;
    return 0;
}
