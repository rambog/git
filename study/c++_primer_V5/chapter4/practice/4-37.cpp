/*======================================================================
*        filename: 4-37.cpp
*        author: rambogui
*        data: 2018-12-20 16:36:19
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int i;
    double d;
    const std::string *ps;
    char *pc;
    void *pv;

    pv = const_cast<std::string*>(ps);
    i = static_cast<int>(*pc);
    pv = static_cast<void*>(&d);
    pc = static_cast<char*>(pv);

    return 0;
}
