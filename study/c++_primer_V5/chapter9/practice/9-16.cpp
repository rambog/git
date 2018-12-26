/*======================================================================
*        filename: 9-16.cpp
*        author: rambogui
*        data: 2018-12-26 10:49:45
======================================================================*/

#include <iostream>
#include <list>
#include <vector>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

unsigned
operator== (const vector<int> &ivec, const list<int> &ilst)
{
    vector<int>::const_iterator vecbeg = ivec.begin(),
                                vecend = ivec.end();
    list<int>::const_iterator lstbeg = ilst.begin(),
                              lstend = ilst.end();
    
    if (ivec.size() != ivec.size()) return false;

    while (vecbeg != vecend && lstbeg != lstend) {
        if (*vecbeg++ != *lstbeg++) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    list<int> ilst = {1, 2, 3, 4, 5};

    if (ivec == ilst)
        cout << "equal\n";

    return 0;
}
