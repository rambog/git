/*======================================================================
*        filename: forstr2.cpp
*        author: rambogui
*        data: 2018-11-27 10:33:18
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "Enter a word: ";
    string word;
    cin >> word;

    char temp;
    int i,j;
    for (j = 0, i = word.size()-1; j < i; --i, ++j)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << "\nDone\n";

    return 0;
}
