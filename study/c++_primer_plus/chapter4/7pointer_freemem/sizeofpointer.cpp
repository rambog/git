/*======================================================================
*        filename: sizeofpointer.cpp
*        author: rambogui
*        data: 2018-11-26 09:43:39
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(char *) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(short *) << endl;
    cout << sizeof(long long *) << endl;
    cout << sizeof(wchar_t *) << endl;
    cout << sizeof(long double *) << endl;
    cout << sizeof(float *) << endl;

    return 0;
}
