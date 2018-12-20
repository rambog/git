/*======================================================================
*        filename: goto.cpp
*        author: rambogui
*        data: 2018-12-20 22:47:05
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int cnt = 5;

begin:
    int tmp;
    std::cout << &tmp << std::endl;
    --cnt;
    if (cnt)
        goto begin;

    return 0;
}
