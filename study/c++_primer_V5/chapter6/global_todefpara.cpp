/*======================================================================
*        filename: global_todefpara.cpp
*        author: rambogui
*        data: 2018-12-22 09:10:18
======================================================================*/

#include <iostream>
#include <string>

using std::string;

string str = "rambo";
int idx = 1;

void foo(int = idx, string = str);

int main(int argc, char *argv[])
{
    string str = "guiyao";

    foo();

    return 0;
}

void foo(int i, string str)
{
    std::cout << i << ' ' << str << std::endl;
}
