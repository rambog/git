/*======================================================================
*        filename: 9-27.cpp
*        author: rambogui
*        data: 2018-12-27 10:21:01
======================================================================*/

#include <iostream>
#include <forward_list>

using std::forward_list;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    forward_list<int> iflst = {1,2,3,4,5,6,7,8,9,10,11,12,13,15,18,19,19,20,20,20};

    for (auto tmp : iflst)
        cout << tmp << ' ';
    cout << endl;

    forward_list<int>::iterator prev, curr;
    prev = iflst.before_begin();
    curr = iflst.begin();

    while (curr != iflst.end()) {
        if (*curr % 2 == 1) {
            curr = iflst.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }

    for (auto tmp : iflst)
        cout << tmp << ' ';
    cout << endl;
    return 0;
}
