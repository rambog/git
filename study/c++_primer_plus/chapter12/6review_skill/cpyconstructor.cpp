/*======================================================================
*        filename: cpyconstructor.cpp
*        author: rambogui
*        data: 2018-12-10 14:23:37
======================================================================*/

#include <iostream>

class foo
{
private:
    char *str;
    int len;
public:
    foo() { str = nullptr; len = 0; }
    foo(const foo &);
    ~foo();

    foo& operator= (const foo &f);
};

int main(int argc, char *argv[])
{
    foo f1;
    foo f2 = foo(f1);
    return 0;
}

foo::foo(const foo &f)
{
    using namespace std;
    cout << "I am cpy constructor!\n";
}

foo::~foo()
{

}

foo& foo::operator= (const foo &f)
{
    if (this == &f)
        return *this;
    
    delete [] str;
}
