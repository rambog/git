/*======================================================================
*        filename: lambda_biggies.cpp
*        author: rambogui
*        data: 2019-01-03 08:28:24
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    vector<string> sv = {"rambo", "lambda", "guiyao", "guibingsheng", "zhangtaoxiang",
                            "guiyuanfen", "lilian", "sunny", "cenkun", "liulin", "wangyu",
                            "luoyue", "sunny", "darren", "cody", "zhangwentao", "rinima",
                            "baby", "adult", "biggies", "function", "string", "vector",
                            "vector", "rambo", "guiyao","guibingsheng", "zhangtaoxiang"};

    sort(sv.begin(), sv.end());
    vector<string>::iterator newend = unique(sv.begin(), sv.end());
    sv.erase(newend, sv.end());
    stable_sort(sv.begin(), sv.end(),
                [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });

    int sz = 6;
    vector<string>::iterator finditer = find_if(sv.begin(), sv.end(),
                                    [sz](const string &s)
                                    { return s.size() >= sz; });
    for_each(finditer, sv.end(), [](const string &s) { cout << s << " "; });
    cout << endl;

    return 0;
}
