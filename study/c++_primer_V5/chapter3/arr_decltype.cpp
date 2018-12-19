/*======================================================================
*        filename: arr_decltype.cpp
*        author: rambogui
*        data: 2018-12-19 16:53:31
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int ia[10];
    decltype(ia) ia2;

    std::cout << sizeof ia2 << std::endl;

    return 0;
}
