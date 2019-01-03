/*======================================================================
*        filename: 10-18.cpp
*        author: rambogui
*        data: 2019-01-03 09:34:37
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void biggies(vector<string> sv, vector<string>::size_type sz)
{
    auto rep = unique(sv.begin(), sv.end());
    sv.erase(rep, sv.end());

    auto newbeg = partition(sv.begin(), sv.end(), 
                            [sz](const string &s) -> bool
                            { return s.size() < sz; });
    sort(sv.begin(), newbeg); 
    stable_sort(sv.begin(), newbeg, 
                [](const string &s1, const string &s2) -> bool
                { return s1.size() > s2.size(); });
    for_each(sv.begin(), newbeg, [](const string &s)
                                    { cout << s << ' ';});
    cout << endl;
}

int main(int argc, char *argv[])
{
    
    vector<string> sv = {"rambo", "lambda", "guiyao", "guibingsheng", "zhangtaoxiang",
                            "guiyuanfen", "lilian", "sunny", "cenkun", "liulin", "wangyu",
                            "luoyue", "sunny", "darren", "cody", "zhangwentao", "rinima",
                            "baby", "adult", "biggies", "function", "string", "vector",
                            "vector", "rambo", "guiyao","guibingsheng", "zhangtaoxiang"};
    biggies(sv, 6);
    return 0;
}
