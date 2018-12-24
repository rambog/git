/*======================================================================
*        filename: 6-47.cpp
*        author: rambogui
*        data: 2018-12-22 09:46:59
======================================================================*/

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

int main(int argc, char *argv[])
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

    for (auto i : ivec) {
        assert(i < 5);
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
