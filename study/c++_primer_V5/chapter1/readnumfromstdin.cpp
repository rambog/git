/*======================================================================
*        filename: readnumfromstdin.cpp
*        author: rambogui
*        data: 2018-12-17 14:06:37
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0, value = 0;
    while (std::cin >> value)
        sum += value;

    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
