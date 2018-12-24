/*======================================================================
*        filename: assert.cpp
*        author: rambogui
*        data: 2018-12-22 09:41:47
======================================================================*/

#include <iostream>
#include <cassert>

int main(int argc, char *argv[])
{
    signed tmp1, tmp2;

    while (std::cin >> tmp1 >> tmp2) {
        assert(tmp1 < tmp2);
        std::cout << "max is " << tmp2 << std::endl;
    }

    return 0;
}
