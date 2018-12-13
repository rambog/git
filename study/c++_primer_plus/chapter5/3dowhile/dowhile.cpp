/*======================================================================
*        filename: dowhile.cpp
*        author: rambogui
*        data: 2018-11-27 14:12:22
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int n;

    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n";
    do {
        cin >> n;
    } while (n != 7);


    cout << "Yes, 7 is my favorite.\n";
    return 0;
}
