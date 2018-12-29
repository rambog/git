/*======================================================================
*        filename: 10-2.cpp
*        author: rambogui
*        data: 2018-12-29 08:28:07
======================================================================*/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;

int main(int argc, char *argv[])
{
    list<string> sv;
    string tmp;
    
    while (cin >> tmp) {
        sv.push_back(tmp);
    }
    cin.clear();
    cin >> tmp;
    cout << count(sv.begin(), sv.end(), tmp) << endl;

    return 0;
}
