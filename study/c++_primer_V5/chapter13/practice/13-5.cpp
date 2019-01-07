/*======================================================================
*        filename: 13-5.cpp
*        author: rambogui
*        data: 2019-01-07 09:23:04
======================================================================*/

#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &lhp) : 
        ps(new std::string(*lhp.ps)), i(lhp.i) { }
private:
    std::string *ps;
    int i;
};

int main(int argc, char *argv[])
{
    HasPtr hp1;
    HasPtr hp2(hp1);
    return 0;
}
