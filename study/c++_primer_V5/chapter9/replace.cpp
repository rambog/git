/*======================================================================
*        filename: replace.cpp
*        author: rambogui
*        data: 2018-12-27 17:33:32
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    string s("C++ Primer");
    s.insert(s.size(), " 4th Ed.");
    s.replace(s.begin(), 3, "Fifth");
    return 0;
}
