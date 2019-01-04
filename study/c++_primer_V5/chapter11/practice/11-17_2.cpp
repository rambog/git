/*======================================================================
*        filename: 11-17_2.cpp
*        author: rambogui
*        data: 2019-01-04 15:27:53
======================================================================*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

using std::map;
using std::vector;
using std::string;
using std::set;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<string> sv = {"rambo", "guiyao", "hello"};
    set<string> sset1, sset2;

    copy(sv.begin(), sv.end(), inserter(sset1, sset1.end()));
    copy(sv.begin(), sv.end(), inserter(sset2));

    for_each(sset1.begin(), sset1.end(), [](const string &s)
        { cout << s << ' '; });
    cout << endl;

    for_each(sset2.begin(), sset2.end(), [](const string &s)
        { cout << s << ' '; });
    cout << endl;

    return 0;
}
