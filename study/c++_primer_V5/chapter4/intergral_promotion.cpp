/*======================================================================
*        filename: intergral_promotion.cpp
*        author: rambogui
*        data: 2018-12-20 15:48:44
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int i = -100;
    unsigned long long lli = 30;

    std::cout << lli+i << std::endl;
    std::cout << sizeof(lli+i) << std::endl;

    return 0;
}
