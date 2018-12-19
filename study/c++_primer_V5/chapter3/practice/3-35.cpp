/*======================================================================
*        filename: 3-35.cpp
*        author: rambogui
*        data: 2018-12-19 17:14:43
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *parr = arr;

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        *(parr+i) = 0;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        std::cout << arr[i] << std::endl;
        
    return 0;
}
