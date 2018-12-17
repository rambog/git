/*======================================================================
*        filename: 1-9while50_to100.cpp
*        author: rambogui
*        data: 2018-12-17 13:35:40
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int val = 50;
    int sum = 0;

    while (val <= 100) {
        sum += val;
        ++val;
    }

    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;

    return 0;
}
