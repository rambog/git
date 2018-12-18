/*======================================================================
*        filename: ref.cpp
*        author: rambogui
*        data: 2018-12-18 13:23:58
======================================================================*/

#include <iostream>

int global = 100;

int main(int argc, char *argv[])
{
    int i = 10;
    int i2 = 100;
    int *pi = &i;

    //int &iref;
    int &iref = i;
    int &gref = global;
    int *(&pref) = pi;
    int &refref = iref;

    std::cout << *pref << std::endl;

    (*pref)++;

    std::cout << refref << std::endl;

    return 0;
}
