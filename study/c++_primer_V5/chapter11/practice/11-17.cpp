/*======================================================================
*        filename: 11-17.cpp
*        author: rambogui
*        data: 2019-01-04 15:14:26
======================================================================*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::set;
using std::string;
using std::vector;

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    set<string> sset = {"rambo", "guiyao", "hello"};
    vector<string> sv1, sv2;

    copy(sset.begin(), sset.end(), inserter(sv1, sv1.end()));
    copy(sset.begin(), sset.end(), back_inserter(sv2));
   
    for_each(sv1.begin(), sv1.end(), [](const string &s)
        { cout << s << ' '; });

    cout << endl;

    for_each(sv2.begin(), sv2.end(), [](const string &s)
        { cout << s << ' '; });
    cout << endl;

    return 0;
}
