/*======================================================================
*        filename: operatoroverlad.cpp
*        author: rambogui
*        data: 2018-12-08 09:08:07
======================================================================*/

#include <iostream>

double operator+ (const double &, const double &);

int main(int argc, char *argv[])
{

    return 0;
}

double operator+ (const double &d1, const double &d2)
{
    return d1+d2;
}
