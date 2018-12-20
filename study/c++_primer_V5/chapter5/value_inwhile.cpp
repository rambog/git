/*======================================================================
*        filename: value_inwhile.cpp
*        author: rambogui
*        data: 2018-12-20 17:13:50
======================================================================*/

#include <iostream>

int get_num()
{
    return 0;
}

int main(int argc, char *argv[])
{
    while (int i = get_num())
        std::cout << i << std::endl;
    return 0;
}
