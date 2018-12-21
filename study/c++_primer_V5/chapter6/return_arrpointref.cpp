/*======================================================================
*        filename: return_arrpointref.cpp
*        author: rambogui
*        data: 2018-12-21 16:09:02
======================================================================*/

#include <iostream>

int (*retarrpoint(int (*arr)[10]))[10]
{
    //return static_cast<int(*)[10]>(arr);
    for (auto &a : *arr)
        a++;
    return arr;
}

int (&retarrpoint(int (&ref)[10]))[10]
{
    //return static_cast<int(&)[10]>(ref);
    return ref;
}

int main(int argc, char *argv[])
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; ++i)
        std::cout << (*retarrpoint(&arr))[i] << ' ';
    std::cout << std::endl;

    for (int i = 0; i <10; ++i)
        std::cout << (retarrpoint(arr))[i] << ' ';
    std::cout << std::endl;

    return 0;
}
