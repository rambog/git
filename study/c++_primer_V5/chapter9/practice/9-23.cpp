/*======================================================================
*        filename: 9-23.cpp
*        author: rambogui
*        data: 2018-12-27 08:56:08
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> ivec{1};

    std::cout << ivec.size() << ' ' << ivec[0] << std::endl;

    auto val = *ivec.begin(), val2 = ivec.front();
    auto last = ivec.end();
    auto val3 = *(--last);
    auto val4 = ivec.back();

    std::cout << val << ' ' << val2 << ' ' << val3 << ' ' << val4 << std::endl;
    std::cout << &val << ' ' << &val2 << ' ' << &val3 << ' ' << &val4 << std::endl;

    return 0;
}
