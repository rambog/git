/*======================================================================
*        filename: if.cpp
*        author: rambogui
*        data: 2018-11-28 08:22:12
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using std::cin;
    using std::cout;

    char ch;
    int spaces = 0;
    int total = 0;
    cin.get(ch);
    while (ch != '.') {
        if (ch == ' ')
            ++spaces;
        ++total;
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";

    return 0;
}
