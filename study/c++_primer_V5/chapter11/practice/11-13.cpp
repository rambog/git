/*======================================================================
*        filename: 11-13.cpp
*        author: rambogui
*        data: 2019-01-04 13:52:02
======================================================================*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<pair<string, int>> pv1, pv2, pv3;

    string str;
    int i;

    while (cin >> str >> i) {
        pv1.push_back({str,i});
        pv2.push_back(pair<string, int>(str, i));
        pv3.push_back(make_pair(str, i));
    }

    cout << "pv1: " << endl;
    for_each(pv1.begin(), pv1.end(),
        [](const pair<string, int> &p)
        { cout << p.first << ' ' << p.second << endl; });

    cout << "pv2: " << endl;
    for_each(pv1.begin(), pv1.end(),
        [](const pair<string, int> &p)
        { cout << p.first << ' ' << p.second << endl; });

    cout << "pv3: " << endl;
    for_each(pv1.begin(), pv1.end(),
        [](const pair<string, int> &p)
        { cout << p.first << ' ' << p.second << endl; });

    return 0;
}
