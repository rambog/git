/*======================================================================
*        filename: arr_scoreidx.cpp
*        author: rambogui
*        data: 2018-12-19 16:41:46
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    unsigned scores[11] = {};
    unsigned grade;

    while (std::cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }

    for (auto i : scores)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
