/*======================================================================
*        filename: refpara_overload.cpp
*        author: rambogui
*        data: 2018-12-01 11:06:59
======================================================================*/

#include <iostream>

void foo(int);
void foo(const int &);

int main(int argc, char *argv[])
{
    int tmp = 0;
    const int &ref2 = 10;
    const int fo = 10;

    foo(tmp);

    return 0;
}

void foo(int n1)
{

}

void foo(const int &n1)
{
}
