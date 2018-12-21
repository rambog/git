/*======================================================================
*        filename: 6-5.cpp
*        author: rambogui
*        data: 2018-12-21 08:45:01
======================================================================*/

#include <iostream>

int myabs(int val)
{
    if (val < 0)
        return -val;
    return val;
}

int main(int argc, char *argv[])
{
    int n;

    while (std::cin >> n) {
        std::cout << "the abs of " << n << " is " << myabs(n) << std::endl;
    }

    return 0;
}
