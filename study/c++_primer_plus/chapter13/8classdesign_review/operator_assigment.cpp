/*======================================================================
*        filename: operator_assigment.cpp
*        author: rambogui
*        data: 2018-12-13 09:00:12
======================================================================*/

#include <iostream>

class base
{
public:
    base& operator=(const base &b) 
    { std::cout << "I am base=" << std::endl; return *this; }
};

class derive : public base
{

};

int main(int argc, char *argv[])
{
    derive d;
    derive d2;

    d2 = d;
    return 0;
}
