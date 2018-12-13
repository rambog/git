/*======================================================================
*        filename: const_ref_pointer.cpp
*        author: rambogui
*        data: 2018-12-06 10:27:18
======================================================================*/

#include <iostream>

const int & foo(const int &para)
{
    return para;
}

int main(int argc, char *argv[])
{
    int tmp = 10;

    const int *ptmp = &tmp;
    const int &rtmp = tmp;

    std::cout << *ptmp << ' ' << rtmp << std::endl;

    int *p = (int *)ptmp;
    int &r = (int &)rtmp;

    *p = 11;
    r = 12;

    std::cout << *p << ' ' << r << ' ' << tmp << std::endl;
    std::cout << p << ' ' << &r << ' ' << &tmp << std::endl;

    r = (int &)foo(tmp);
    r = 13;

    std::cout << &r << std::endl;
    std::cout << tmp << std::endl;

    return 0;
}
