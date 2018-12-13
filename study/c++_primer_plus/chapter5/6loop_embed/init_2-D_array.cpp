/*======================================================================
*        filename: init_2-D_array.cpp
*        author: rambogui
*        data: 2018-11-27 15:46:02
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    int maxtemps[][5] = {
        {96, 100, 87, 101, 105},
        {96, 98, 91, 1, 2},
        {3, 4, 5, 6, 7},
        {10, 11, 12, 13, 14}
    };
    
    int maxtmp[] = {1, 2, 4, 5};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++)
            cout << maxtemps[i][j] << " ";
        cout << endl;
    }
    return 0;
}
