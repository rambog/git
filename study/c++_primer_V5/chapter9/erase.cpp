/*======================================================================
*        filename: erase.cpp
*        author: rambogui
*        data: 2018-12-27 09:08:58
======================================================================*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    std::vector<int> ivec(10, 11);

    auto beg = ivec.begin(), end = ivec.end();
    cout << &ivec[0] << endl;
    ivec.erase(beg+5, end);
    cout << &ivec[0] << endl;
    if (end == ivec.end())
        cout << "equal\n";

    return 0;
}
