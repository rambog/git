/*======================================================================
*        filename: strings.cpp
*        author: rambogui
*        data: 2018-11-24 13:34:45
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";
    int tmp[4] = {1,2};

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    return 0;
}
