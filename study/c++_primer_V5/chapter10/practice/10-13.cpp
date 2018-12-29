/*======================================================================
*        filename: 10-13.cpp
*        author: rambogui
*        data: 2018-12-29 14:04:55
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

bool morefive(const string &s)
{
    return s.size() >= 5;
}

int main(int argc, char *argv[])
{
    vector<string> sv;
    string tmp;

    while (cin >> tmp)
        sv.push_back(tmp);

    vector<string>::iterator iter = partition(sv.begin(), sv.end(), morefive);

    for (auto tmp : sv)
        cout << tmp << ' ';
    cout << endl;
    cout << *iter << endl;

    return 0;
}
