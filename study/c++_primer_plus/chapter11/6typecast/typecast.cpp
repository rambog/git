/*======================================================================
*        filename: typecast.cpp
*        author: rambogui
*        data: 2018-12-08 14:27:00
======================================================================*/

#include <iostream>

class foo
{
private:
    int f1;
    double f2;
public:
    foo() { f1 = 0; f2 = 0.0; }
    explicit foo(int n) { f1 = n; f2 = 0.0; }
    
    void show();
};

int main(int argc, char *argv[])
{
    foo f1;
    f1.show();
    f1 = (foo)1143424;
    f1.show();

    foo f2;
    f2.show();
    f2 = (foo)1;
    f2.show();
    

    return 0;
}

void foo::show()
{
    using namespace std;

    cout << "int : " << f1 << endl;
    cout << "double : " << f2 << endl;
    cout << endl;
}
