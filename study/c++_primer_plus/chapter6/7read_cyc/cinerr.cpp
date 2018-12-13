/*======================================================================
*        filename: cinerr.cpp
*        author: rambogui
*        data: 2018-11-28 15:35:44
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    int tmp = 0;

    cin >> tmp;
    cin.clear();
    cin >> tmp;
    cin.clear();
    if (cin.fail())
        cout << "error" << endl;
    cout << tmp << endl;

    return 0;
}
