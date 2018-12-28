/*======================================================================
*        filename: 9-19.cpp
*        author: rambogui
*        data: 2018-12-27 08:09:10
======================================================================*/

#include <iostream>
#include <string>
#include <list>
#include <deque>

using std::string;
using std::list;
using std::deque;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    string temp;
    list<string> strdeq;

    while (cin >> temp)
        strdeq.emplace_back(temp);

    list<string>::const_iterator iter = strdeq.begin();
    while (iter != strdeq.end())
        cout << *iter++ << ' ';
    cout << endl;

    return 0;
}
