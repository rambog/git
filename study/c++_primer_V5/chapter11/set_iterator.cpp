/*======================================================================
*        filename: set_iterator.cpp
*        author: rambogui
*        data: 2019-01-04 10:03:20
======================================================================*/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using std::string;
using std::set;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    set<string> setstr = {"rambo", "guiayo", "hellp",
                        "baby", "set", "map", "iterator"};

    set<string>::iterator iter = setstr.begin();
    while (iter != setstr.end())
        cout << *iter++ << " ";
    cout << endl;

    for_each(setstr.cbegin(), setstr.cend(),
            [](const string &s) { cout << s << ' '; });
    cout << endl;

    return 0;
}
