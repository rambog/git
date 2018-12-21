/*======================================================================
*        filename: funcpara_passed.cpp
*        author: rambogui
*        data: 2018-12-21 09:28:55
======================================================================*/

#include <iostream>

void passedby_ref(int &ref)
{
    std::cout << &ref << std::endl;
}

void passedby_val(int *p)
{
    std::cout << &p << std::endl;
    std::cout << p << std::endl;
}

int main(int argc, char *argv[])
{
    int tmp;

    std::cout << &tmp << std::endl;
    passedby_val(&tmp);
    passedby_ref(tmp);

    return 0;
}
