/*======================================================================
*        filename: hexoct.cpp
*        author: rambogui
*        data: 2018-11-23 10:54:51
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int chest = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    cout << endl;

    return 0;
}
