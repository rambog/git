/*======================================================================
*        filename: 3.cpp
*        author: rambogui
*        data: 2018-11-27 09:17:07
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;
    const int len = 80;
    char foostr[len] = {0};
    char *pfoo;

    cout << "Enter your first name: ";
    cin >> foostr;
    pfoo = &foostr[strlen(foostr)];
    *pfoo++ = ',';
    *pfoo++ = ' ';
    cout << "Enter your last name: ";
    cin >> pfoo;

    cout << "Here's the information in a single string: ";
    cout << foostr << endl;

    return 0;
}
