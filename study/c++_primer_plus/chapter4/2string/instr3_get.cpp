/*======================================================================
*        filename: instr3_get.cpp
*        author: rambogui
*        data: 2018-11-24 13:55:18
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
   
    cout << "Enter your name:\n";
    cin.get(name,ArSize).get();
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, ArSize).get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    return 0;
}
