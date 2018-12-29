/*======================================================================
*        filename: 10-1.cpp
*        author: rambogui
*        data: 2018-12-29 08:22:57
======================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> iv;
    int input;

    std::cout << "Please input line number:";
    while (std::cin >> input) {
        iv.push_back(input);
    }
    std::cin.clear();
    std::cout << "input target:";
    std::cin >> input;

    std::cout << "in line the target num: "
              << count(iv.begin(), iv.end(), input) << std::endl;

    return 0;
}
