/*======================================================================
*        filename: map.cpp
*        author: rambogui
*        data: 2019-01-04 08:22:32
======================================================================*/

#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
