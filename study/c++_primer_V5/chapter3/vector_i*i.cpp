/*======================================================================
*        filename: vector_i*i.cpp
*        author: rambogui
*        data: 2018-12-19 13:27:20
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    for (auto &i : v)
        i *= i;
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
