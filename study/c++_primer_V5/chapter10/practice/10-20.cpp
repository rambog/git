/*======================================================================
*        filename: 10-20.cpp
*        author: rambogui
*        data: 2019-01-03 10:37:37
======================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int countnum(const vector<string> &words, 
                vector<string>::size_type sz)
{
    return count_if(words.begin(), words.end(),
                    [sz](const string &s) -> bool
                    { return s.size() > sz; });
}

int main(int argc, char *argv[])
{
    vector<string> sv;
    string tmp;

    while (cin >> tmp)
        sv.push_back(tmp);
    std::cout << countnum(sv, 6) << std::endl;

    return 0;
}
