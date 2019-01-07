/*======================================================================
*        filename: 13-2.cpp
*        author: rambogui
*        data: 2019-01-07 08:57:12
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class foo {
private:
    string s;
public:
    foo(foo &rhs) : s(rhs.s) { }
};

int main(int argc, char *argv[])
{

    return 0;
}
