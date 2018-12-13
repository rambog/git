/*======================================================================
*        filename: delete.cpp
*        author: rambogui
*        data: 2018-11-26 14:57:51
======================================================================*/

#include <iostream>
#include <cstring>

using namespace std;
char *getname(void);

int main(int argc, char *argv[])
{
    char *name;

    name = getname();
    cout << name << " at " << (int *)name << "\n";
    delete [] name;

    name = getname();
    cout << name << " at " << (int *)name << "\n";
    delete [] name;

    return 0;
}

char *getname()
{
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);

    return pn;
}
