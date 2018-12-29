/*======================================================================
*        filename: replace.cpp
*        author: rambogui
*        data: 2018-12-29 10:43:33
======================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>


int main(int argc, char *argv[])
{
    std::vector<int> iv = {1,1,2,2,3,3};
    for (int tmp : iv)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    replace(iv.begin(), iv.end(), 2, 100);

    for (int tmp : iv)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    return 0;
}
