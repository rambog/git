/*======================================================================
*        filename: new2segm.cpp
*        author: rambogui
*        data: 2018-12-03 17:50:55
======================================================================*/

#include <iostream>
#include <new>

int buf[8*1024*1024];

void foo()
{
    int *tmp = NULL;
    while (1) {
        tmp = new(buf) int[1024*1024];
    }
}

int main(int argc, char *argv[])
{
    foo();
    return 0;
}
