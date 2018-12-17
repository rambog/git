/*======================================================================
*        filename: 1-9for50_to100add.cpp
*        author: rambogui
*        data: 2018-12-17 13:55:52
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0;

    for (int val = 50;
        val <= 100; ++val)
        sum += val;

    std::cout << "Sum of 50 to 100: " << sum << std::endl;

    return 0;
}
