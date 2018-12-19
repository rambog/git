/*======================================================================
*        filename: string_add.cpp
*        author: rambogui
*        data: 2018-12-19 09:22:07
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;
    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;
    s1 += s2;

    cout << s1;
    cout << s3;

    return 0;
}
