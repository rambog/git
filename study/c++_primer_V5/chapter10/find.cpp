/*======================================================================
*        filename: find.cpp
*        author: rambogui
*        data: 2018-12-29 08:09:29
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char *argv[])
{
    std::vector<int> iv = {1,2,3,4,5,6,7,8,9,10}; 

    int tmp;

    while (std::cin >> tmp) {
        std::vector<int>::iterator iter = find(iv.begin(), iv.end(), tmp);
        std::cout << "the val " << tmp
             << (iter == iv.end() ? " is not present" : " is present") << std::endl;
        if (iter != iv.end())
            std::cout << *iter << std::endl;
    }

    return 0;
}
