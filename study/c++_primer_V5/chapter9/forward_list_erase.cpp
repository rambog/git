/*======================================================================
*        filename: forward_list_erase.cpp
*        author: rambogui
*        data: 2018-12-27 09:50:53
======================================================================*/

#include <iostream>
#include <vector>
#include <forward_list>

using std::vector;
using std::forward_list;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    int ai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> ivec(std::begin(ai), std::end(ai));
    forward_list<int> iflst(std::begin(ai), std::end(ai));

    for (auto tmp : ivec)
        cout << tmp << ' ';
    cout << endl;
    for (auto tmp : iflst)
        cout << tmp << ' ';
    cout << endl;

    ivec.erase(ivec.begin()+5, ivec.end()-1);
#if 0
    iflst.erase_after(iflst.begin(), iflst.end());
#else
    forward_list<int>::iterator prev, start, end, curr;
    int cnt = 5;
    for (prev = iflst.before_begin(), curr = iflst.begin();
            curr != iflst.end(); --cnt) {
            if (cnt > 0) start = curr; 
            prev = curr;
            ++curr;
    }
    end = prev;
    cout << *start << ' ' << *end << endl;
    iflst.erase_after(start, end);
#endif

    for (auto tmp : ivec)
        cout << tmp << ' ';
    cout << endl;
    for (auto tmp : iflst)
        cout << tmp << ' ';
    cout << endl;

    forward_list<int> iflst1 = {10, 11, 12, 13};
    iflst.insert_after(iflst.before_begin(), iflst1.begin(), iflst1.end());
    for (auto tmp : iflst)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
