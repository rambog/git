/*======================================================================
*        filename: 9-41.cpp
*        author: rambogui
*        data: 2018-12-27 13:57:13
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[])
{
    vector<char> cv = {'r','a','m','b','o'}; 
    string str(cv.begin(), cv.end());
    cout << str << endl;
    return 0;
}
