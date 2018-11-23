/*======================================================================
*        filename: assign.cpp
*        author: rambogui
*        data: 2018-11-23 16:58:20
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess{3.9832};
    int debt = 7.2E12;
    char c1 {31325};

    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    cout << "c1 - " << c1 << endl;
    return 0;
}
