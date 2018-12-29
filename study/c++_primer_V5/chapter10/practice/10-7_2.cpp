/*======================================================================
*        filename: 10-7_2.cpp
*        author: rambogui
*        data: 2018-12-29 11:02:42
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> vec;

    //vec.reserve(10);
    vec.resize(10);
    fill_n(vec.begin(), 10, 100);

    for (auto i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
