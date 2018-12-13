/*======================================================================
*        filename: main.cpp
*        author: rambogui
*        data: 2018-12-03 16:13:10
======================================================================*/

#include <iostream>

static int foo();
//int foo2();

int main(int argc, char *argv[])
{
    using namespace std; 

    foo();
    //cout << "main call :" << (void*)foo << endl;

    return 0;
}

#if 0
int foo()
{
    using namespace std;

    cout << "I am foo in main.cpp" << endl;
    cout << "foo2 func: ";
    foo2();
    return 0;
}
#endif
