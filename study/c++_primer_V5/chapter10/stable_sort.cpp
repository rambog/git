/*======================================================================
*        filename: stable_sort.cpp
*        author: rambogui
*        data: 2018-12-29 13:33:46
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char *argv[])
{
    vector<string> sv = {"rambojfeio", "giuya", "tmepp", "pinkk", "adultfie", "peopl","zinkk",
                            "guiayo", "zhnagtaoxinag", "pinka", "temooa"};

    //sort(sv.begin(), sv.end());
    for (auto tmp : sv)
        cout << tmp << ' ';
    cout << endl;

    vector<string> svb(sv);

    sort(sv.begin(), sv.end(), isShorter);
    stable_sort(svb.begin(), svb.end(), isShorter);

    for (auto tmp : sv)
        cout << tmp << ' ';
    cout << endl;

    for (auto tmp : svb)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
