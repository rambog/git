/*======================================================================
*        filename: 9-39.cpp
*        author: rambogui
*        data: 2018-12-27 13:46:05
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
    vector<string> svec;
    svec.reserve(1024);
    svec.push_back("rambo");
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    svec.resize(0);
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    return 0;
}
