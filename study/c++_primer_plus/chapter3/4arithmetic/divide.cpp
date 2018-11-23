/*======================================================================
*        filename: divide.cpp
*        author: rambogui
*        data: 2018-11-23 16:40:32
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << 9/5 << endl;
    cout << 9.0/5.0 << endl;
    cout << 9.0F/5.0F << endl;
    cout << 9.0/5 << endl;

    cout << 1.e7 / 9.0 << endl;
    cout << 1.e7f / 9.0f << endl;
    cout << 1.e7 / 9.0f << endl;

    return 0;
}
