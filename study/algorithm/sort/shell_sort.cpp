/*======================================================================
*        filename: shell_sort.cpp
*        author: rambogui
*        data: 2019-01-09 08:49:29
======================================================================*/

#include <iostream>

void ShellSort(int *arr, int size)
{
    int i, j, tmp, increment;

    for (increment = size/2; increment > 0; increment /= 2) {
        for (i = increment; i < size; i++) {
            tmp = arr[i];
            for (j = i - increment; j >=0 && tmp < arr[j]; i -= increment) {
                arr[j+increment] = arr[j];
            }
            arr[j+increment] = tmp;
        }
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
