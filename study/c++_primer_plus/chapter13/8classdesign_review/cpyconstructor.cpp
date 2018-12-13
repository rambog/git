/*======================================================================
*        filename: cpyconstructor.cpp
*        author: rambogui
*        data: 2018-12-13 08:28:27
======================================================================*/

#include <iostream>

class base
{
public:
    base(const base &b) {std::cout<<"base cpy constructor"<<std::endl;}
    base() {}
};

class derive : public base
{
public:
    derive(const derive &d) {std::cout<<"derive cpy constructor"<<std::endl;}
    derive() {}
};

int main(int argc, char *argv[])
{
    derive d;
    derive d2 = d;
    base b = d;
    return 0;
}
