/*======================================================================
*        filename: lambda_capture_list.cpp
*        author: rambogui
*        data: 2018-12-29 14:51:51
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;

vector<string>::const_iterator
find_iflambda(const vector<string> &sv, string::size_type sz)
{
    auto f = [sz](const string &s) -> bool { return s.size() >= sz; }; 
    return find_if(sv.begin(), sv.end(), f);
}

int main(int argc, char *argv[])
{
    vector<string> sv;
    string tmp;
    while (cin >> tmp) {
        sv.push_back(tmp);
    }

    sort(sv.begin(), sv.end(), [](const string &s1, const string s2)
                                { return s1.size() < s2.size(); });

    for (auto tmp : sv)
        cout << tmp << ' ';
    cout << endl;

    //cout << *(find_iflambda(sv, strlen("rambo"))) << endl;
    cout << *(find_iflambda(sv, string("rambo").size())) << endl;

    return 0;
}
