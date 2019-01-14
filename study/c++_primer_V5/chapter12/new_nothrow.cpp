/*======================================================================
*        filename: new_nothrow.cpp
*        author: rambogui
*        data: 2019-01-14 14:29:47
======================================================================*/

#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    //int *p = new int[1024*1024*1024];
    int *p2 = new (std::nothrow) int[1024*1024*1024];

    if (p2)
        std::cout << "new success!\n";
    else
        std::cout << "new fail!\n";

    return 0;
}
