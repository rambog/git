/*======================================================================
*        filename: 3-14.cpp
*        author: rambogui
*        data: 2018-12-19 13:18:49
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec;

    int temp;
    while (std::cin >> temp)
        ivec.push_back(temp);

    std::cout << "size: " << ivec.size() << std::endl;
    for (auto i : ivec)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
