/*======================================================================
*        filename: textin1.cpp
*        author: rambogui
*        data: 2018-11-27 14:56:43
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;
    while (ch != '#') {
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl << count << " characters read\n";

    return 0;
}
