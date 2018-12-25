/*======================================================================
*        filename: 7-43.cpp
*        author: rambogui
*        data: 2018-12-25 10:59:40
======================================================================*/

#include <iostream>

class NoDefault {
public:
    NoDefault(int i) : tmp(i) { }
private:
    int tmp;
};

class C {
private:
    NoDefault def;
public:
    C(int i = 0) : def(i) { }
};

int main(int argc, char *argv[])
{
    C c;
    return 0;
}
