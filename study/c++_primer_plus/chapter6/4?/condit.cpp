/*======================================================================
*        filename: condit.cpp
*        author: rambogui
*        data: 2018-11-28 10:57:42
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int a,b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "The larger of " << a << " and " << b;
    int c = a > b ? a : b;
    cout << " is " << c << endl;

    return 0;
}
