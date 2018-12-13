/*======================================================================
*        filename: compstr2.cpp
*        author: rambogui
*        data: 2018-11-27 11:25:52
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    string word = "?ate";
    for (char ch = 'a'; word != "mate"; ch++) {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;

    return 0;
}
