/*======================================================================
*        filename: static_cast.cpp
*        author: rambogui
*        data: 2018-12-20 16:11:29
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    const int i = 10;
    const int &iref = i;

    double slope = static_cast<double>(iref);
    //double &dref = static_cast<double &>(iref);
    int &dref = const_cast<int &>(iref);

    std::cout << &i << ' ' << &iref << ' ' << &dref << std::endl;
    dref++;
    std::cout << i << ' ' << dref <<  std::endl;

    return 0;
}
