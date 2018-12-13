/*======================================================================
*        filename: compstr1.cpp
*        author: rambogui
*        data: 2018-11-27 11:21:56
======================================================================*/

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;

    char word[5] = "?ate";

    for (char ch = 'a'; strcmp(word, "mate"); ch++) {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;

    return 0;
}
