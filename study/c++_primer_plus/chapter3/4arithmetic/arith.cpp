/*======================================================================
*        filename: arith.cpp
*        author: rambogui
*        data: 2018-11-23 16:16:55
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;

    return 0;
}
