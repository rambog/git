/*======================================================================
*        filename: 3-31.cpp
*        author: rambogui
*        data: 2018-12-19 16:47:16
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    constexpr int size = 10;
    int arr[size] = {};

    for (int i = 0; i < size; ++i)
        arr[i] = i;

    for (int i = 0; i < size; ++i)
        std::cout << "idx:" << i << " value:" << arr[i] << std::endl;

    return 0;
}
