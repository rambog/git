/*======================================================================
*        filename: 1-16cin_sum.cpp
*        author: rambogui
*        data: 2018-12-17 14:19:10
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int val = 0, sum = 0;

    std::cout << "please enter some num: ";
    while (std::cin >> val)
        sum += val;

    std::cout << "the sum of input: " << sum << std::endl;

    return 0;
}
