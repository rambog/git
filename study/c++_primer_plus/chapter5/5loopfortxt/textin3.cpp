/*======================================================================
*        filename: textin3.cpp
*        author: rambogui
*        data: 2018-11-27 15:31:26
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    char ch;
    int count = 0;
    cin.get(ch);
    while (cin.fail() == false) {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";

    return 0;
}
