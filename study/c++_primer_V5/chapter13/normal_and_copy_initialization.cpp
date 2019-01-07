/*======================================================================
*        filename: normal_and_copy_initialization.cpp
*        author: rambogui
*        data: 2019-01-07 08:32:17
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
    foo(const char *cs);
    foo(const foo &);
};

foo::foo(const char *cs) : fstr(cs)
{
    cout << "normal constructor\n";
}

foo::foo(const foo &origf) : fstr(origf.fstr)
{
    cout << "copy constructor\n";
}

int main(int argc, char *argv[])
{
    foo f1("guiyao");
    cout << endl;
    foo f2 = "guiyao";
    cout << endl;
    foo f3 = f2;
    cout << endl;
    foo f4[2] = {"guiyao", "guiyao"};
    cout << endl;
    foo f5[2] = {f1, f2};
    return 0;
}
