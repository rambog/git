/*======================================================================
*        filename: 11-7.cpp
*        author: rambogui
*        data: 2019-01-04 09:48:40
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::string;
using std::vector;
using std::map;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, vector<string>> familys;

    string word;

    while (cin >> word) {
        string name;
        while (cin >> name)
            familys[word].push_back(name);
        cin.clear();
    }

    for (const auto &family : familys) {
        cout << family.first << ": ";
        for_each(family.second.cbegin(), family.second.cend(),
                [](const string &s) { cout << s << " "; });
        cout << endl;
    }

    return 0;
}
