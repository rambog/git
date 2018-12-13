/*======================================================================
*        filename: textin2.cpp
*        author: rambogui
*        data: 2018-11-27 15:24:45
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);
    while (ch != '#') {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";

    return 0;
}
