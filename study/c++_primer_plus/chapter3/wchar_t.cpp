/*======================================================================
*        filename: wchar_t.cpp
*        author: rambogui
*        data: 2018-11-23 13:45:54
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    cout << sizeof(wchar_t) << endl;
    wchar_t bob = L'P';
    wcout << bob << endl;
    wcout << L"I am a wchat_ string" << endl;
    return 0;
}
