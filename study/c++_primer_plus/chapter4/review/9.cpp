/*======================================================================
*        filename: 9.cpp
*        author: rambogui
*        data: 2018-11-27 08:26:02
======================================================================*/

#include <iostream>

struct fish
{
    int type;
    int weight;
    float len;
};

int main(int argc, char *argv[])
{
    fish foo = {1, 100, 12.5};

    using std::cout;
    using std::endl;

    cout << foo.type << endl;
    cout << foo.weight << endl;
    cout << foo.len << endl;

    return 0;
}
