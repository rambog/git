/*======================================================================
*        filename: sizeofclass.cpp
*        author: rambogui
*        data: 2018-12-07 08:09:02
======================================================================*/

#include <iostream>

class foo
{
private:
    int f1;
    int f2;
    int f3;
public:
    foo() {}
    foo(const int &, const int &);
    void show();
};

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(foo) << endl;

    return 0;
}

foo::foo(const int &n1, const int &n2)
{
    f1 = n1;
    f2 = n2;
}

void foo::show()
{
    using namespace std;
    cout << f1 << ' ' << f2 << ' ' << f3 << endl;
}
