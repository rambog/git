/*======================================================================
*        filename: bigstep.cpp
*        author: rambogui
*        data: 2018-11-27 10:06:13
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";
    for (int i = 0; i < 100 ;i += by)
        cout << i << endl;
    return 0;
}
