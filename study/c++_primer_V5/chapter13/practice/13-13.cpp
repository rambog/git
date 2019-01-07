/*======================================================================
*        filename: 13-13.cpp
*        author: rambogui
*        data: 2019-01-07 09:57:19
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class X {
    X() { cout << "X()" << endl; }
    X(const X &x) { cout << "X(const X &x)" << endl; }
    X &operator= (const X &X)
    { cout << "operator=" << endl; }
    ~X() { cout << "~X()" << endl; }
};

int main(int argc, char *argv[])
{

    return 0;
}
