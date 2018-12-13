/*======================================================================
*        filename: address.cpp
*        author: rambogui
*        data: 2018-11-26 09:12:00
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    double donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts <<endl;

    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;

    cout << (long long)&donuts - (long long)&cups << endl;

    return 0;
}
