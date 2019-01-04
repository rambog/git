/*======================================================================
*        filename: map_insert.cpp
*        author: rambogui
*        data: 2019-01-04 16:54:53
======================================================================*/

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using std::string;
using std::pair;
using std::map;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        pair<map<string, size_t>::iterator, bool> ret = 
            word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }

    for (const auto &p : word_count) {
        cout << p.first << " occur " << p.second
             << (p.second > 1 ? " times" : " time") << endl;
    }

    return 0;
}
