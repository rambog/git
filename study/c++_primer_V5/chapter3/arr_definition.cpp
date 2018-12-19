/*======================================================================
*        filename: arr_definition.cpp
*        author: rambogui
*        data: 2018-12-19 16:07:37
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int cnt;
    constexpr int sz = 10;

    int arr1[cnt];
    int arr2[sz];
    int arr3[10];

    auto arr4[10] = cnt;
    int &arr5[10];

    return 0;
}
