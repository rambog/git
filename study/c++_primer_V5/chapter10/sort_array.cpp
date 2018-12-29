/*======================================================================
*        filename: sort_array.cpp
*        author: rambogui
*        data: 2018-12-29 11:19:04
======================================================================*/

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::string array[10];

    int i = 0;

    while (i < 10 && (std::cin >> array[i]))
        ++i;

    sort(begin(array), end(array));
    std::cout << (unique(begin(array), end(array))) - array << std::endl;


    for (auto i : array)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
