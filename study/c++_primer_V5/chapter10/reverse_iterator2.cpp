/*======================================================================
*        filename: reverse_iterator2.cpp
*        author: rambogui
*        data: 2019-01-03 16:42:23
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    sort(vec.rbegin(), vec.rend()); 
    for (auto r_iter = vec.crbegin();
                r_iter != vec.crend();
                ++r_iter)
        std::cout << *r_iter << ' ';
    std::cout << std::endl;
    return 0;
}
