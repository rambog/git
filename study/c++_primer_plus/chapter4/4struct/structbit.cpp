/*======================================================================
*        filename: structbit.cpp
*        author: rambogui
*        data: 2018-11-24 16:55:00
======================================================================*/

#include <iostream>

struct torgle_register
{
    unsigned int SN:4;
    unsigned int :4;
    bool goodI:1;
    bool goodTorgle:1;
    unsigned int tmp:4;
};

struct foo
{
    int foo1;
    int foo2;
    int foo3;
    char foo4;
    int foo5;
}__attribute__((packed));

struct nfoo
{
    int foo1;
    char foo2;
    short foo3;
    int foo4;
};

int main(int argc, char *argv[])
{
    using namespace std;
    cout << sizeof(torgle_register) << endl;
    cout << sizeof(foo) << endl;
    cout << sizeof(nfoo) << endl;
    return 0;
}
