/*======================================================================
*        filename: sizeofclass.cpp
*        author: rambogui
*        data: 2018-12-06 08:35:25
======================================================================*/

#include <iostream>

class foo1
{
private:
    int f_d1;
    int f_d2;
    int f_d3;
public:
    foo1();
    foo1(int, int, int);
    void f_f1();
    void f_f2();
    void show();
};

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(foo1) << endl;

    foo1 f1;
    foo1 f2 = foo1(10, 11, 12);

    f1.show();
    f2.show();

    cout << "after = " << endl;
    f1 = f2;
    f1.show();
    f2.show();

    return 0;
}


foo1::foo1()
{
    f_d1 = 1;
    f_d2 = 2;
    f_d3 = 3;
}

foo1::foo1(int p1, int p2, int p3)
{
    f_d1 = p1;
    f_d2 = p2;
    f_d3 = p3;
}

void foo1::f_f1()
{

}

void foo1::f_f2()
{

}

void foo1::show()
{
    std::cout << f_d1 << ' ' << f_d2 << ' ' << f_d3 << std::endl;
}
