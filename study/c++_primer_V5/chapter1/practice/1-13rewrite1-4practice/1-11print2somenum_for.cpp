/*======================================================================
*        filename: 1-11print2somenum_for.cpp
*        author: rambogui
*        data: 2018-12-17 14:00:27
======================================================================*/

#include <iostream>

void printsomedata(int max, int min)
{
    int val = 0;

    for (val = min; val <= max; ++val)
        std::cout << val << ' ';
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int val1,val2;

    std::cout << "enter two number: ";
    std::cin >> val1 >> val2;

    if (val1 < val2)
        printsomedata(val2, val1);
    else
        printsomedata(val1, val2);

    return 0;
}
