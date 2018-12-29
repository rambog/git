/*======================================================================
*        filename: predicate.cpp
*        author: rambogui
*        data: 2018-12-29 13:26:31
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool min(int i1, int i2)
{
    return i1 > i2;
}

int main(int argc, char *argv[])
{
    vector<string> sv = {"rambo", "rambo", "guiyao", "guibings",
                            "zhangtaoxinag", "sunny", "leo", "pink", "adukt"};
    vector<int> iv = {1,2,3,4,5,6,5,4,3,2,1};

    sort(sv.begin(), sv.end(), isShorter);
    sort(iv.begin(), iv.end(), min);

    for (auto tmp : sv)
        cout << tmp << ' ';
    cout << endl;

    for (auto tmp : iv)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
