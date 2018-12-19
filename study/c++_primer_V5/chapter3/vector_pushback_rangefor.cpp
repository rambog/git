/*======================================================================
*        filename: vector_pushback_rangefor.cpp
*        author: rambogui
*        data: 2018-12-19 11:35:06
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec(10);

    for (auto i : ivec) {
        ivec.push_back(10);
        std::cout << "tmp" << std::endl;
    }
    std::cout << ivec.size() << std::endl;

    return 0;
}
