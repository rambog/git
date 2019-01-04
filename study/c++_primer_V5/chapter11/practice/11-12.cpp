/*======================================================================
*        filename: 11-12.cpp
*        author: rambogui
*        data: 2019-01-04 13:47:09
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
    vector<pair<string, int>> pv;

    string str;
    int i;

    while (cin >> str >> i)
        pv.push_back({str, i});

    for_each(pv.begin(), pv.end(),
        [](const pair<string, int> &p)
        { cout << p.first << ' ' << p.second << endl; });

    return 0;
}
