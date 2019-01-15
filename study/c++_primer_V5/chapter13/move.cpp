/*======================================================================
*        filename: move.cpp
*        author: rambogui
*        data: 2019-01-15 08:49:51
======================================================================*/

#include <iostream>
#include <utility>

int main(int argc, char *argv[])
{
    int tmp = 4;
    int &&rr = std::move(tmp);
    tmp = 5;

    std::cout << rr << std::endl;
    std::cout << tmp << std::endl;
    std::cout << tmp*4 << std::endl;

    return 0;
}
