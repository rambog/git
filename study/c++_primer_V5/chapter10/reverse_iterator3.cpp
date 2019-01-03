/*======================================================================
*        filename: reverse_iterator3.cpp
*        author: rambogui
*        data: 2019-01-03 16:55:41
======================================================================*/

#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    string str;
    getline(cin, str);

    auto first = find(str.begin(), str.end(), ',');
    cout << string(str.begin(), first) << endl;

    auto last = find(str.rbegin(), str.rend(), ',');
    cout << string(last.base(), str.end()) << endl;

    return 0;
}
