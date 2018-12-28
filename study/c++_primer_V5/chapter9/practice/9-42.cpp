/*======================================================================
*        filename: 9-42.cpp
*        author: rambogui
*        data: 2018-12-27 13:59:22
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    char c;
    string str; 
    str.reserve(100);
    std::cout << str.capacity() << std::endl;

    while (cin >> c) {
        str.push_back(c);
    }

    cout << str << endl;

    return 0;
}
