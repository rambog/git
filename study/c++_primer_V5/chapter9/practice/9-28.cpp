/*======================================================================
*        filename: 9-28.cpp
*        author: rambogui
*        data: 2018-12-27 10:27:34
======================================================================*/

#include <iostream>
#include <forward_list>
#include <string>

using std::string;
using std::forward_list;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    forward_list<string> sflst = {"rambo", "gui", "yao", "guiyao",
                    "rambogui", "guiyaoyao", "ramgui", "ramyao"};

    for (string tmp : sflst)
        cout << tmp << ' ';
    cout << endl;

    string tmp1, tmp2;
    tmp1 = "guii";
    tmp2 = "guiyaoyao";

    forward_list<string>::iterator prev, curr;
    prev = sflst.before_begin();
    curr = sflst.begin();
    while (curr != sflst.end()) {
        if (*curr == tmp1) {
            sflst.insert_after(curr, tmp2);
            break;
        }
        prev = curr; ++curr;
    }

    if (curr == sflst.end())
        sflst.insert_after(prev, tmp2);

    for (string tmp : sflst)
        cout << tmp << ' ';
    cout << endl;
    return 0;
}
