/*======================================================================
*        filename: fact.cpp
*        author: rambogui
*        data: 2018-12-21 09:20:20
======================================================================*/

#include <iostream>

int fact(int val)
{
    int ret = 1;
    while (val >= 1)
        ret *= val--;

    return ret;
}
