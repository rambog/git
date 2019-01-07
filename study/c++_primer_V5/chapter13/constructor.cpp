/*======================================================================
*        filename: constructor.cpp
*        author: rambogui
*        data: 2019-01-07 08:41:50
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class foo {
private:
    string fstr;
public:
    foo(const string &s) : fstr(s) { }
};

int main(int argc, char *argv[])
{
    string str = "guiyao";
    //foo f = "guiyao";
    foo f = str;
    return 0;
}
