/*======================================================================
*        filename: multiset.cpp
*        author: rambogui
*        data: 2019-01-04 09:43:14
======================================================================*/

#include <iostream>
#include <set>
#include <vector>

using std::vector;
using std::multiset;
using std::endl;
using std::cout;
using std::cin;
using std::set;

int main(int argc, char *argv[])
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;

    return 0;
}
