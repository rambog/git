/*======================================================================
*        filename: vector_pushback.cpp
*        author: rambogui
*        data: 2018-12-19 11:24:00
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> v2;

    for (int i = 0; i < 100; ++i) {
        std::cout << v2.size() << ' ';
        v2.push_back(i);
    }
    std::cout << v2.size() << std::endl;

    return 0;
}
