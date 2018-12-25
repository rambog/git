/*======================================================================
*        filename: 7-31.cpp
*        author: rambogui
*        data: 2018-12-25 08:07:00
======================================================================*/

#include <iostream>

class Y;

class X {
private:
    Y *py;
};

class Y {
private:
    X *px;
};

int main(int argc, char *argv[])
{

    return 0;
}
