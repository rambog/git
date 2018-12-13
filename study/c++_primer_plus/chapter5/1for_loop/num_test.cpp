/*======================================================================
*        filename: num_test.cpp
*        author: rambogui
*        data: 2018-11-27 09:36:54
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    int i;
    for (i = limit; i; i--)
        cout << "i = " << i << '\n';
    cout << "Done now that i = " << i << '\n';

    return 0;
}
