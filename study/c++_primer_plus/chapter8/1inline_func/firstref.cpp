/*======================================================================
*        filename: firstref.cpp
*        author: rambogui
*        data: 2018-11-30 10:23:27
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int rats = 101;
    int &rodents = rats;

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}
