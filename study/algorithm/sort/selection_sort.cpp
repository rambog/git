/*======================================================================
*        filename: selection_sort.cpp
*        author: rambogui
*        data: 2019-01-09 08:33:31
======================================================================*/

#include <iostream>

void SelectionSort(int *arr, int size)
{
    int i, j, k, tmp;
    for (i = 0; i < size - 1; i++) {
        k = i;
        for (j = i + 1; i < size; j++) {
            if (arr[j] < arr[k])
                k = j;
        }
        tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
