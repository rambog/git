/*======================================================================
*        filename: 3-10.cpp
*        author: rambogui
*        data: 2018-12-19 10:20:05
======================================================================*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    string str;
    getline(cin, str);

    for (auto c : str)
        if (!ispunct(c))
            cout << c;
    cout << endl;

    return 0;
}
