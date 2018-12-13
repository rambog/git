/*======================================================================
*        filename: ptrstr.cpp
*        author: rambogui
*        data: 2018-11-26 14:03:20
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;

    char animal[20] = "bear";
    const char *bird = "wren";
    char *ps;

    cout << animal << " and ";
    cout << bird << "\n";

    cout << "Enter a kind of animal: ";
    cin >> animal;

    ps = animal;
    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    ps = new char[strlen(animal)+1];
    strcpy(ps, animal);
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;
    delete [] ps;

    return 0;
}