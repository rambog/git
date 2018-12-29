/*======================================================================
*        filename: fill.cpp
*        author: rambogui
*        data: 2018-12-29 09:30:47
======================================================================*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> iv = {1,2,3,4,5,6,7,8,9};

    for (int tmp : iv)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    fill(iv.begin(), iv.end()-5, 0);

    for (int tmp : iv)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    return 0;
}
