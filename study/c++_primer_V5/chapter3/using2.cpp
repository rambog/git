/*======================================================================
*        filename: using2.cpp
*        author: rambogui
*        data: 2018-12-19 08:35:34
======================================================================*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    cout << "Enter two numbers:" << endl;
    int v1, v2;
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and " << v2
         << " is " << v1+v2 << endl;
    return 0;
}
