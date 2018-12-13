/*======================================================================
*        filename: 13.cpp
*        author: rambogui
*        data: 2018-11-27 08:54:00
======================================================================*/

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    using namespace std;
    int numelem;
    int *ptarget;
   
    cin >> numelem;
    cout << numelem <<endl;

    ptarget = new int[numelem];
    vector<int> vec(numelem);

    cout << sizeof vec << endl;

    delete [] ptarget;

    return 0;
}
