/*======================================================================
*        filename: sceref.cpp
*        author: rambogui
*        data: 2018-11-30 10:31:13
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int rats = 101;
    int &rodents = rats;

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}
