/*======================================================================
*        filename: 6-7.cpp
*        author: rambogui
*        data: 2018-12-21 09:12:39
======================================================================*/

#include <iostream>

int foo()
{
    static int cnt;
    return cnt++;
}

int main(int argc, char *argv[])
{
    for (size_t iter = 0; iter != 10; ++iter)
        std::cout << foo() << std::endl;
    return 0;
}
