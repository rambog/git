/*======================================================================
*        filename: 2.cpp
*        author: rambogui
*        data: 2018-11-27 08:00:07
======================================================================*/

#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
    std::array<char, 30> actor;
    std::array<short, 100> betsie;
    std::array<float, 13> chuck;
    std::array<long double, 64> dipsea;

    using std::cout;
    using std::endl;

    cout << sizeof actor << endl;
    cout << sizeof betsie << endl;
    cout << sizeof chuck << endl;
    cout << sizeof dipsea << endl;

    return 0;
}
