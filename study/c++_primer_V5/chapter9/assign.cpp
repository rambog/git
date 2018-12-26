/*======================================================================
*        filename: assign.cpp
*        author: rambogui
*        data: 2018-12-26 10:14:34
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char *argv[])
{
    vector<int> ivec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    std::cout << &ivec1[0] << std::endl;

    ivec1.assign(ivec2.begin(), ivec2.end());
    for (int temp : ivec1)
        std::cout << temp << ' ';
    std::cout << std::endl;
    std::cout << &ivec1[0] << std::endl;

    return 0;
}
