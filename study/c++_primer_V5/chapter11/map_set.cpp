/*======================================================================
*        filename: map_set.cpp
*        author: rambogui
*        data: 2019-01-04 08:40:11
======================================================================*/

#include <iostream>
#include <map>
#include <set>
#include <string>

using std::string;
using std::map;
using std::set;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
