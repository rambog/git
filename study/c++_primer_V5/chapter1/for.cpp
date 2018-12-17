/*======================================================================
*        filename: for.cpp
*        author: rambogui
*        data: 2018-12-17 13:49:51
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0;

    for (int val = 1; val <= 10; ++val) 
        sum += val;

    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    return 0;
}
