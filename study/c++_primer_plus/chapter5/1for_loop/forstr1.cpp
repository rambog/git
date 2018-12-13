/*======================================================================
*        filename: forstr1.cpp
*        author: rambogui
*        data: 2018-11-27 10:09:34
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "Enter a word: ";
    string word;
    cin >> word;

    for (int i = word.size()-1; i >= 0; i--)
        cout << word[i];

    cout << "\nBye.\n";

    return 0;
}
