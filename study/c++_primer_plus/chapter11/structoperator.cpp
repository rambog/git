/*======================================================================
*        filename: structoperator.cpp
*        author: rambogui
*        data: 2018-12-07 16:58:31
======================================================================*/

#include <iostream>

struct foo
{
    int f1;
    int f2;
    std::string str;
};

foo operator+(const foo &, const foo &);

void show(const foo &);
//void show(foo &);

int main(int argc, char *argv[])
{
    foo f1 = {10, 10, "rambo"};
    foo f2 = {10, 10, "guiyao"};

    show(f1+f2);

    return 0;
}

foo operator+(const foo &f1, const foo &f2)
{
    foo tmp;

    tmp.f1 = f1.f1 + f2.f1;
    tmp.f2 = f1.f2 + f2.f2;
    tmp.str = f1.str + f2.str;

    return tmp;
}

void show(const foo &f)
//void show(foo &f)
{
    using namespace std;

    cout << "f1: " << f.f1 << endl;
    cout << "f2: " << f.f2 << endl;
    cout << "str: " << f.str << endl;
}
