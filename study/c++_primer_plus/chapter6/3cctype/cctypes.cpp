/*======================================================================
*        filename: cctypes.cpp
*        author: rambogui
*        data: 2018-11-28 10:41:51
======================================================================*/

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "Enter text for analysis, and type @"
            " to terminate input.\n";

    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    while (cin.get(ch) && ch != '@') {
        if (isalpha(ch)) 
            chars++;
        else if (isspace(ch))
            whitespace++;
        else if (ispunct(ch))
            punct++;
        else
            others++;
    }

    cout << chars << " letters, "
         << whitespace << " whitespace, "
         << digits << " digits, "
         << punct << " punctuations, "
         << others << " others.\n";

    return 0;
}
