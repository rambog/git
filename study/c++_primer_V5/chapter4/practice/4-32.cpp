/*======================================================================
*        filename: 4-32.cpp
*        author: rambogui
*        data: 2018-12-20 15:25:24
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};
    for (int *ptr = ia, ix = 0;
        ix != size && ptr != ia+size; 
        ++ix, ++ptr)
        std::cout << ia[ix] << ' ' << *ptr << std::endl;;
    return 0;
}
