/*======================================================================
*        filename: insertion_sort.cpp
*        author: rambogui
*        data: 2019-01-09 08:40:00
======================================================================*/

#include <iostream>

void InsertionSort(int *arr, int size)
{
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        if (arr[i] < arr[i-1]) {
            tmp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = tmp;
        }
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
