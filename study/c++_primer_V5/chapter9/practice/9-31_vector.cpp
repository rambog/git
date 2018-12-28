/*======================================================================
*        filename: 9-31_vector.cpp
*        author: rambogui
*        data: 2018-12-27 11:02:32
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else
            iter = vi.erase(iter);
    }
    
    for (auto tmp : vi)
        cout << tmp << ' ';
    cout << endl;

    return 0;
}
