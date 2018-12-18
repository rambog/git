/*======================================================================
*        filename: void_pointer.cpp
*        author: rambogui
*        data: 2018-12-18 14:19:43
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    double obj = 3.14, *pd = &obj;

    void *pv = &obj;
    pv = pd;

    return 0;
}
