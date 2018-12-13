/*======================================================================
*        filename: instr2_getline.cpp
*        author: rambogui
*        data: 2018-11-24 13:48:21
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    return 0;
}
