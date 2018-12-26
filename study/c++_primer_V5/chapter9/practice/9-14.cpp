/*======================================================================
*        filename: 9-14.cpp
*        author: rambogui
*        data: 2018-12-26 10:20:48
======================================================================*/

#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;
using std::cin;
using std::endl;
using std::cout;

int main(int argc, char *argv[])
{
    list<const char *> clst = {"rambo", "guiyao", "rambogui"};
    vector<string> svec = {"gy"};

    cout << &svec[0] << endl;

    svec.assign(clst.begin(), clst.end());
    for (auto tmp : svec)
        cout << tmp << ' ';
    cout << endl;

    cout << &svec[0] << endl;

    return 0;
}
