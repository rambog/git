/*======================================================================
*        filename: vtbl.cpp
*        author: rambogui
*        data: 2018-12-11 16:55:54
======================================================================*/

#include <iostream>

class nbase
{
private:
    int n1;
public:
    void show();
    void show2();
};

class nderive : public nbase
{
private:
    int n2;
public:
    void show();
    void show2();
};

class vbase
{
private:
    int n1;
public:
    virtual void show();
    virtual void show2();
};

class vderive : public vbase
{
private:
    int n2;
public:
    void show();
    void show2();
};

int main(int argc, char *argv[])
{
    using namespace std;

    cout << sizeof(void*) << endl << endl;
    cout << sizeof(nbase) << endl;
    cout << sizeof(nderive) << endl;
    cout << endl;
    cout << sizeof(vbase) << endl;
    cout << sizeof(vderive) << endl;

    return 0;
}
