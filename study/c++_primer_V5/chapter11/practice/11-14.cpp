/*======================================================================
*        filename: 11-14.cpp
*        author: rambogui
*        data: 2019-01-04 14:02:22
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using std::string;
using std::vector;
using std::pair;
using std::map;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    map<string, vector<pair<string, string>>> familys;

    string firstname;
    string lastname;
    string birthday;

    while (cin >> firstname) {
        while (cin >> lastname >> birthday) {
            familys[firstname].push_back(
                {lastname, birthday});
        }
        cin.clear();
        cout << endl;
        cout << "please enter last family\n";
    }

    for (const pair<string, vector<pair<string, string>>> &p : familys) {
        cout << "family " << p.first << ":\n";
        for_each(p.second.begin(), p.second.end(),
            [p](const pair<string, string> &pn)
            { cout << "name: " << p.first << pn.first
                   << " birthday: " << pn.second<< endl;});
        cout << endl;
    }

    return 0;
}
