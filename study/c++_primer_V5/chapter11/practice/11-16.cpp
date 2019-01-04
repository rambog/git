/*======================================================================
*        filename: 11-16.cpp
*        author: rambogui
*        data: 2019-01-04 14:47:12
======================================================================*/

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using std::map;
using std::pair;
using std::multimap;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    multimap<int, int> imap = {{0,0},
                          {0,1},
                          {0,2},
                          {0,3},
                          {0,4},
                          {0,5},
                          {0,6},
                          {0,7},
                          {0,8},
                          {0,9},
                          {0,10},
                          {0,11}};

    for_each(imap.begin(), imap.end(),
        [](const pair<int, int> &p)
        { cout << p.first << p.second << ' '; });
    cout << endl;

    multimap<int, int>::iterator iter = imap.begin();
    while (iter != imap.end()) {
        ++((iter++)->second);
    }

    for_each(imap.begin(), imap.end(),
        [](const pair<int, int> &p)
        { cout << p.first << p.second << ' '; });
    cout << endl;

    return 0;
}
