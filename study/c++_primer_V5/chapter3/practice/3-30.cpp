/*======================================================================
*        filename: 3-30.cpp
*        author: rambogui
*        data: 2018-12-19 16:45:24
======================================================================*/

#include <iostream>
#include <cstddef>

int main(int argc, char *argv[])
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix;
    return 0;
}
