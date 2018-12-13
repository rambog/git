/*======================================================================
*        filename: pointer.cpp
*        author: rambogui
*        data: 2018-11-26 09:38:22
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int updates = 6;
    int * p_updates;
    p_updates = &updates;

    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;

    return 0;
}
