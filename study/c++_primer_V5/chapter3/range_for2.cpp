/*======================================================================
*        filename: range_for2.cpp
*        author: rambogui
*        data: 2018-12-19 09:47:51
======================================================================*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    string s("Hello World!!!");
    //for (auto &c : s)
    for (decltype(s[0]) c : s)
        c = toupper(c);
    cout << s << endl;

    return 0;
}
