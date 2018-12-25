/*======================================================================
*        filename: inout_tie.cpp
*        author: rambogui
*        data: 2018-12-25 15:48:53
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "guiyao";
    int i;
    std::ostream *old_tie = std::cin.tie(nullptr);
    std::cin >> i;
    return 0;
}
