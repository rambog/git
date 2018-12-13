/*======================================================================
*        filename: 12.cpp
*        author: rambogui
*        data: 2018-11-27 08:50:49
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    float treacle[10] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    float *ptrea = treacle;

    cout << ptrea[0] << endl;
    cout << ptrea[9] << endl;

    return 0;
}
