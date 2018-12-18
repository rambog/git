/*======================================================================
*        filename: sizeof_buildin_type.cpp
*        author: rambogui
*        data: 2018-12-18 08:12:33
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "sizeof(bool): " << sizeof(bool) << endl << endl;

    cout << "sizeof(char): " << sizeof(char) << endl;
    cout << "sizeof(wchar_t): " << sizeof(wchar_t) << endl;
    cout << "sizeof(char16_t): " << sizeof(char16_t) << endl;
    cout << "sizeof(char32_t): " << sizeof(char32_t) << endl << endl;

    cout << "sizeof(short): " << sizeof(short) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(long long): " << sizeof(long long) << endl << endl;

    cout << "sizeof(float): " << sizeof(float) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(long double: " << sizeof(long double) << endl;

    return 0;
}
