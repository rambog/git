/*======================================================================
*        filename: 3-19.cpp
*        author: rambogui
*        data: 2018-12-19 14:01:12
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> v1 {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    std::vector<int> v2(10, 42);
    std::vector<int> v3;
    for (int i = 0; i < 10; ++i)
        v3.push_back(42);

    for (auto i : v1)
        std::cout << i << ' ';
    std::cout << std::endl;

    for (auto i : v2)
        std::cout << i << ' ';
    std::cout << std::endl;

    for (auto i : v3)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
