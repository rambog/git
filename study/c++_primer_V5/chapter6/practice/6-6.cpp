/*======================================================================
*        filename: 6-6.cpp
*        author: rambogui
*        data: 2018-12-21 09:10:28
======================================================================*/

#include <iostream>

void foo(int i)
{
    int local = 0;
    static int lstatic = 0;

    std::cout << ++lstatic << ' ' << ++local << ' ' << ++i << std::endl;
}

int main(int argc, char *argv[])
{
    for (size_t idx = 0; idx <= 10; ++idx)
        foo(idx);
    return 0;
}
