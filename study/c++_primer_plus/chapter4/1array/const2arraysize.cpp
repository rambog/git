/*======================================================================
*        filename: const2arraysize.cpp
*        author: rambogui
*        data: 2018-11-24 09:53:38
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    const int size = 10;
    int intarray[size];
    //auto autoarray[4] = {0, 0, 0, 0};

    cout << sizeof(intarray) << " " << sizeof(&intarray) << endl; 

    cout << intarray << " " << intarray+1 << endl;
    cout << &intarray << " " << &intarray+1 << endl;

    return 0;
}
