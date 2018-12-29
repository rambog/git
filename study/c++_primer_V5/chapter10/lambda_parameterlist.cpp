/*======================================================================
*        filename: lambda_parameterlist.cpp
*        author: rambogui
*        data: 2018-12-29 14:40:41
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    bool (*flambda)(const string&, const string&) = 
        [](const string &s1, const string &s2) -> bool
        { return s1.size() < s2.size(); };

    vector<string> sv;
    string stmp;
    while (cin >> stmp)
        sv.push_back(stmp);

    sort(sv.begin(), sv.end(), flambda);

    for (auto tmp : sv)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
