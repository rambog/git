/*======================================================================
*        filename: exceed.cpp
*        author: rambogui
*        data: 2018-11-23 10:15:29
======================================================================*/

#include <iostream>
#include <climits>

#define ZERO 0

int main(int argc, char *argv[])
{
    using namespace std;
    short sam = SHRT_MAX;
    unsigned short sue = sam;

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl
         << "Add $1 to each account." << endl << "Now ";
    sam += 1;
    sue += 1;
    
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\nPorr Sam!" << endl;

    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now ";

    sam = sam - 1;
    sue = sue - 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
    
    return 0;
}
