/*======================================================================
*        filename: abstract3.cpp
*        author: rambogui
*        data: 2018-12-13 13:33:14
======================================================================*/

#include <iostream>

class base
{
public:
    virtual void show() = 0; //{ std::cout << "base show" << std::endl; }
};

class derive : public base
{
public:
    void show() { base::show(); std::cout << "derive show" << std::endl; }
};

int main(int argc, char *argv[])
{
    derive d;
    d.show();
    return 0;
}

void base::show()
{
    std::cout << "base show" << std::endl;
}
