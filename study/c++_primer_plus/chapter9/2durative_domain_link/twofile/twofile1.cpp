/*======================================================================
*        filename: twofile1.cpp
*        author: rambogui
*        data: 2018-12-03 13:29:13
======================================================================*/

#include <iostream>

int tom = 3;
int dick = 30;
static int harry = 300;

void remote_access();

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();

    return 0;
}
