/*======================================================================
*        filename: map_keyorder.cpp
*        author: rambogui
*        data: 2019-01-04 09:27:23
======================================================================*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::map;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, size_t> word_cnt;
    vector<string> sv = {"rambo", "guiyao", "adult", "hello", "bitch",
                        "gay", "fuck", "iterator", "baby", "map", "set"};

    for_each(sv.begin(), sv.end(), 
            [&word_cnt](const string &s){ ++word_cnt[s]; });

    for (string &s : sv)
        cout << s << " ";
    cout << endl;

    for (const std::pair<string, size_t> &w : word_cnt)
        cout << w.first << " ";
    cout << endl;

    sort(sv.begin(), sv.end());
    for (string &s : sv)
        cout << s << " ";
    cout << endl;

    return 0;
}
