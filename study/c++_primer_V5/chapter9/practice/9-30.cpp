/*======================================================================
*        filename: 9-30.cpp
*        author: rambogui
*        data: 2018-12-27 10:55:39
======================================================================*/

#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cin;
using std::cout;

class foo {
private:
    int i1;
    int i2;
public:
    foo(int i1, int i2) : i1(i1), i2(i2) { }
};

int main(int argc, char *argv[])
{
    vector<foo> fv; 

    fv.resize(10, {1,2});

    return 0;
}
