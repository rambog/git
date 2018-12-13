/*======================================================================
*        filename: sizeofenum.cpp
*        author: rambogui
*        data: 2018-11-26 08:35:29
======================================================================*/

#include <iostream>

enum spectrum 
{
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    indigo,
    ultraviolet = ~0,
    tmpfoo
};

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(spectrum) << endl;
    cout << ultraviolet << " " << tmpfoo << endl;

    return 0;
}
