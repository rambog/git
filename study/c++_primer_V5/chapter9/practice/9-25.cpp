/*======================================================================
*        filename: 9-25.cpp
*        author: rambogui
*        data: 2018-12-27 09:22:22
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int>::iterator iter1, iter2, iter3;
    iter1 = ivec.erase(ivec.begin()+3, ivec.begin()+3);
    for (auto tmp : ivec)
        std::cout << tmp << ' ';
    std::cout << std::endl;
    std::cout << iter1 - ivec.begin() << std::endl;

    return 0;
}
