/*======================================================================
*        filename: 4.cpp
*        author: rambogui
*        data: 2018-11-27 09:25:27
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    string first,last;

    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your last name: ";
    cin >> last;

    cout << "Here's the information in a single string: ";
    cout << first + ", " + last << endl;

    return 0;
}
