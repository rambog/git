/*======================================================================
*        filename: const_class.cpp
*        author: rambogui
*        data: 2018-12-18 16:54:48
======================================================================*/

#include <iostream>

class foo
{
private:
    const int size;
    char buff[size];
public:
    explicit foo(int s) : size(s) { }
};

int main(int argc, char *argv[])
{

    return 0;
}
