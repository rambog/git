/*======================================================================
*        filename: pair_relop.cpp
*        author: rambogui
*        data: 2019-01-04 13:38:09
======================================================================*/

#include <iostream>
#include <utility>
#include <string>

using std::string;
using std::pair;

using std::endl;
using std::cout;
using std::cin;

class foo {
};

int main(int argc, char *argv[])
{
    pair<string, string> p1, p3;
    pair<foo, foo> p2;
    pair<int, int> pi1(10,2), pi2(3,4);

    if (p1 < p3)
        ;

    if (pi1 < pi2)
        cout << "rambo\n";

    return 0;
}
