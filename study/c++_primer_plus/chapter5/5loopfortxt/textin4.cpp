/*======================================================================
*        filename: textin4.cpp
*        author: rambogui
*        data: 2018-11-27 15:39:11
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int ch;
    int count = 0;

    while ((ch = cin.get()) != EOF) {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}
