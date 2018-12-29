/*======================================================================
*        filename: 10-6.cpp
*        author: rambogui
*        data: 2018-12-29 10:55:07
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    //std::vector<int> iv = {1,2,3,4,5,6,7,8}; 
    std::vector<int> iv ; 
    fill_n(iv.begin(), iv.size(), 100);

    for (auto tmp : iv)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    return 0;
}
