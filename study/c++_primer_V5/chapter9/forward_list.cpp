/*======================================================================
*        filename: forward_list.cpp
*        author: rambogui
*        data: 2018-12-27 09:46:38
======================================================================*/

#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    while (curr != flst.end()) {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
            prev = curr;
            ++curr;
    }

    return 0;
}
