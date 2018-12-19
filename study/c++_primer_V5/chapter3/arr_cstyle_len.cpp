/*======================================================================
*        filename: arr_cstyle_len.cpp
*        author: rambogui
*        data: 2018-12-19 17:20:50
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    char ca[] = {'C', '+', '+', '\0'};
    std::cout << sizeof ca << std::endl;
    std::cout << strlen(ca) << std::endl;
    return 0;
}
