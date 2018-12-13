/*======================================================================
*        filename: swaps.cpp
*        author: rambogui
*        data: 2018-11-30 10:37:32
======================================================================*/

#include <iostream>
void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);
int main(int argc, char *argv[])
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap content:\n";
    swapr(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointer to swap content again:\n";
    swapp(&wallet1, &wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    
    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    return 0;
}

void swapr(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swapp(int *p, int *q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;
}

void swapv(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
