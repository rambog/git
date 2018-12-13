/*======================================================================
*        filename: err1.cpp
*        author: rambogui
*        data: 2018-11-30 09:58:45
======================================================================*/

#include <iostream>

inline void foo();

int main(int argc, char *argv[])
{
    foo();
    return 0;
}

void foo()
{
    using namespace std;

    cout << "I am foo\n" << endl;

    return;
}

inline void foo()
{
    using namespace std;

    cout << "I am inline foo" << endl;

    return;
}
