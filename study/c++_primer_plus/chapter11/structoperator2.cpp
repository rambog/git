/*======================================================================
*        filename: structoperator2.cpp
*        author: rambogui
*        data: 2018-12-07 17:08:58
======================================================================*/

#include <iostream>

struct foo
{
    int f1;
    int f2;
    std::string str;
};

foo operator+(const foo &, const int &);
foo operator+(const int &, const foo &);

void show(const foo &);

int main(int argc, char *argv[])
{
    foo f1 = { 1, 2, "rambo" };
    
    show(f1+3);
    show(f1+4);

    show(3+f1);
    show(4+f1);

    return 0;
}

foo operator+(const foo &f, const int &n)
{
    foo tmp;
    tmp = f;
    tmp.f1 = f.f1 + n;
    return tmp;
}

foo operator+(const int &n, const foo &f)
{
    foo tmp;
    tmp = f;
    tmp.f2 = f.f2 + n;
    return tmp;
}

void show(const foo &f)
{
    using namespace std;

    cout << f.f1 << ' ' << f.f2 << ' ' << f.str << endl;
}
