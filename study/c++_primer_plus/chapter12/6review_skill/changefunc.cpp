/*======================================================================
*        filename: changefunc.cpp
*        author: rambogui
*        data: 2018-12-10 14:14:10
======================================================================*/

#include <iostream>

class foo
{
private:
    int f1;
public:
    foo(int n = 0) { f1 = n; }
    operator int() { return f1; }
    friend std::ostream& operator<< (std::ostream &os, const foo& f);
};

int main(int argc, char *argv[])
{
    using namespace std;
    foo f1;
    int n1 = 100;
    
    cout << n1 << ' ' << f1 << endl;

    n1 = f1;
    f1 = 100;
    cout << n1 << ' ' << f1 << endl;

    return 0;
}

std::ostream& operator<< (std::ostream &os, const foo& f)
{
    os << f.f1;
    return os;
}
