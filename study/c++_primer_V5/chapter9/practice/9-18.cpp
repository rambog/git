/*======================================================================
*        filename: 9-18.cpp
*        author: rambogui
*        data: 2018-12-26 15:36:36
======================================================================*/

#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    string temp;
    deque<string> strque;

    while (cin >> temp) {
        strque.push_back(temp);
    }

    deque<string>::const_iterator beg = strque.begin();
    while (beg != strque.end())
        cout << *beg++ << ' ';
    cout << endl;

    return 0;
}
