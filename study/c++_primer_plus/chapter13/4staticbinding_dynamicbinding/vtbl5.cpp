/*======================================================================
*        filename: vtbl5.cpp
*        author: rambogui
*        data: 2018-12-12 08:09:54
======================================================================*/

#include <iostream>

class base
{
private:
    int b;
public:
    virtual void show() const { std::cout << "I am base\n"; }
    virtual void show2() const { std::cout << "I am base show2\n"; }
};

class derive : public base
{
private:
    int d;
public:
    virtual void show(int a) const { std::cout << "I am derive\n"; }
};

int main(int argc, char *argv[])
{
    base b;
    derive d;
    std::cout << sizeof b << std::endl;
    std::cout << sizeof d << std::endl << std::endl;

    base *pb;

    pb = &b; pb->show();
    pb = &d; 
    pb->show();

    std::cout << std::endl;
    derive *pd = &d;
    //pd->show();
    //d.show();
    d.show(4);
    d.show2();

    return 0;
}
