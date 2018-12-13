/*======================================================================
*        filename: pointeraccarr.cpp
*        author: rambogui
*        data: 2018-11-29 15:36:48
======================================================================*/

#include <iostream>

int readarr(int **arr, int n, int m);

int main(int argc, char *argv[])
{
    using namespace std;
    int a[][4] = {{1,2,4,5}, {1,2,3,4}};

    cout << sizeof a << endl;
    readarr(&a, 2, 4);

    return 0;
}

int readarr(int **arr, int n, int m)
{
    using namespace std;
    cout << arr[0][0] << endl;
}
