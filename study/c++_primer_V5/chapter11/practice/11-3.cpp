/*======================================================================
*        filename: 11-3.cpp
*        author: rambogui
*        data: 2019-01-04 08:53:28
======================================================================*/

#include <iostream>
#include <string>
#include <map>
#include <set>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::set;

int main(int argc, char *argv[])
{
    map<string, size_t> word_count;
    set<string> exclude = {"rambo", "guiyao", "rambogui"};
    string word;

    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    for (const auto &w : word_count)
        cout << w.first << " occur " << w.second
             << (w.second > 1 ? " times" : " time") << endl;

    return 0;
}
