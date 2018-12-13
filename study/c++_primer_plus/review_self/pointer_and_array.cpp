/*======================================================================
*        filename: pointer_and_array.cpp
*        author: rambogui
*        data: 2018-12-12 18:20:11
======================================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[])
{
    using namespace std;

    char (*pmem)[16] = (char (*)[16])calloc(4, 16);
    
    int idx = 0; 

    for (idx = 0; idx < 4; idx++) {
        sprintf(pmem[idx], "rambo%d", idx);
    }

    for (idx = 0; idx < 4; idx++) {
        cout << pmem[idx] << endl;
        cout << &pmem[idx] << endl;
        cout << (void*)pmem[idx] << endl;
    }

    return 0;
}
