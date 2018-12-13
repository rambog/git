/*======================================================================
*        filename: vtbl2.cpp
*        author: rambogui
*        data: 2018-12-11 17:02:35
======================================================================*/

#include <iostream>

using namespace std;

class base
{
public:
    virtual void show() { cout << "I am base" << endl; }
};

class derive : public base
{
};

class derivederive : public derive
{
public:
    void show() { cout << "I am derivederive" << endl; }
};

int main(int argc, char *argv[])
{
    base b;
    derive d;
    derivederive dd;

    base *pb;

    cout << "use base pointer:\n";
    pb = &b; pb->show();
    pb = &dd; pb->show();
    cout << endl;

    cout << "use derive pointer:\n";
    derive *pd;
    pd = &dd; pd->show();

    return 0;
}
