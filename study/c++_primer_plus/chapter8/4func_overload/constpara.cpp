/*======================================================================
*        filename: constpara.cpp
*        author: rambogui
*        data: 2018-12-01 10:47:36
======================================================================*/

#include <iostream>

int foo(int);
int foop(int *);

int main(int argc, char *argv[])
{
    const int tmp = 10;
    const int *ptmp = &tmp;

    foo(tmp);
    foop(ptmp);

    return 0;
}

int foo(int)
{
    return 0;
}

int foop(int *)
{
    return 0;
}
