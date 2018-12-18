/*======================================================================
*        filename: 2-5.cpp
*        author: rambogui
*        data: 2018-12-18 10:16:38
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << 'a' << ' ' << L'a' << ' ' << "a" << ' ' << L"a" << endl;
    wcout << 'a' << ' ' << L'a' << ' ' << "a" << ' ' << L"a" << endl;
    cout << sizeof('a') << ' ' << sizeof(L'a') << ' ' << sizeof("a") << ' ' << sizeof(L"a") << endl;
    
    cout << endl;
    cout << sizeof(10) << ' ' << sizeof(10u) << ' ' << sizeof (10L) << ' '
         << sizeof(10uL) << ' ' << sizeof(012) << ' ' << sizeof(0xC) << endl;

    cout << endl;
    cout << sizeof(3.14) << ' ' << sizeof(3.14f) << ' ' << sizeof(3.14L) << endl;

    cout << endl;
    cout << sizeof(10) << ' ' << sizeof(10u) << ' ' << sizeof(10.) << ' ' << sizeof(10e-2) << endl;

    return 0;
}
