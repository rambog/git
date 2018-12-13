/*======================================================================
*        filename: array_init{}.cpp
*        author: rambogui
*        data: 2018-11-24 10:18:09
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    int i = 0;
    int arr1[8] = {1, 2, 3};
    int arr2[8] = {5};
    int arr3[8];

    for (i = 0; i < sizeof(arr1)/sizeof(int); i++)
        cout << arr1[i] << " ";
    cout << endl;

    for (i = 0; i < sizeof(arr2)/sizeof(int); i++)
        cout << arr2[i] << " ";
    cout << endl;

    for (i = 0; i < sizeof(arr3)/sizeof(int); i++)
        cout << arr3[i] << " ";
    cout << endl;

    return 0;
}
