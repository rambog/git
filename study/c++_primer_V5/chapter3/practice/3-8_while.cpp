/*======================================================================
*        filename: 3-8_while.cpp
*        author: rambogui
*        data: 2018-12-19 10:12:04
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    string str;
    getline(cin, str);

    string::size_type slen = 0;

    while (slen < str.size()) {
        str[slen++] = 'X';
    }

    cout << str << endl;

    return 0;
}
