/*======================================================================
*        filename: delete.cpp
*        author: rambogui
*        data: 2018-11-26 10:38:14
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    double *p;
    p = new double;
    cout << p << endl;
    p = (double*)((char*)p + 1);
    cout << p << endl;
    //delete p;
    
    int *pi;
    pi = new int [4];
    //pi++;
    delete pi;
    
    float pf;
    return 0;
}
