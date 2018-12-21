/*======================================================================
*        filename: 6-21.cpp
*        author: rambogui
*        data: 2018-12-21 13:23:40
======================================================================*/

#include <iostream>

int foo(int val, int *pval)
{
    if (val > *pval)
        return val;
    return *pval;
}

int main(int argc, char *argv[])
{
    int n1 = 10, n2 = 11; 

    std::cout << foo(n1, &n2) << std::endl;

    return 0;
}
