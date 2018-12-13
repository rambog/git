/*======================================================================
*        filename: covariance_of_returntype.cpp
*        author: rambogui
*        data: 2018-12-12 08:46:16
======================================================================*/

#include <iostream>

class base
{
public:
    virtual base& ret() { return *this; }
};

class derive : public base
{
public:
    virtual derive& ret() { return *this; }
};


int main(int argc, char *argv[])
{
    base b;
    derive d;

    base &bref = d.ret();
    derive &dref = b.ret();

    return 0;
}
