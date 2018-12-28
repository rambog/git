/*======================================================================
*        filename: 9-31_forward_list.cpp
*        author: rambogui
*        data: 2018-12-27 11:12:34
======================================================================*/

#include <iostream>
#include <forward_list>

using std::forward_list;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    forward_list<int> iflst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = iflst.before_begin();
    auto curr = iflst.begin();
    auto end = iflst.end();

    while (curr != end) {
        if (*curr % 2) {
            iflst.insert_after(prev, *curr);
            prev = curr;
            ++curr;
        } else {
            curr = iflst.erase_after(prev);
        }
    }

    for (auto i : iflst)
        cout << i << ' ';
    cout << endl;

    return 0;
}
