/*======================================================================
*        filename: 3-41.cpp
*        author: rambogui
*        data: 2018-12-19 19:24:49
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    int a[5] = {1, 2, 3, 4, 5}; 

    std::vector<int> vec1(a, a+4);
    std::vector<int> vec2(std::begin(a), std::end(a));

    std::cout << vec1.size() << ' ' << vec2.size() << std::endl;

    return 0;
}
