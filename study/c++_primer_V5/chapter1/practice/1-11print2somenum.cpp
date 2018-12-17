/*======================================================================
*        filename: 1-11print2somenum.cpp
*        author: rambogui
*        data: 2018-12-17 13:40:36
======================================================================*/

#include <iostream>

void print2inputallnum(int min, int max)
{
    int val = min;
    while (val <= max) {
        std::cout << val << ' ';
        ++val;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int val1, val2;

    std::cout << "Please two num: ";
    std::cin >> val1 >> val2;

    if (val1 > val2)
        print2inputallnum(val2, val1);
    else
        print2inputallnum(val1, val2);

    return 0;
}
