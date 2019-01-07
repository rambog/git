/*======================================================================
*        filename: 13-4.cpp
*        author: rambogui
*        data: 2019-01-07 09:09:42
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class Point {
private:
public:
    Point() { cout << "def constructor\n"; }
    Point(Point &p) { cout << "copy constructor\n"; }
};

Point global;
Point foo_bar(Point arg)
{
    cout << "In foo_bar";
    cout << endl;
    Point local = arg;
    cout << endl;
    Point *heap = new Point(global);
    cout << endl;
    *heap = local;
    cout << endl;
    cout << "array init\n";
    Point pa[4] = { local, *heap };
    cout << "now return\n";
    return *heap;
}

int main(int argc, char *argv[])
{
    cout << "In main\n";
    foo_bar(global);
    return 0;
}
