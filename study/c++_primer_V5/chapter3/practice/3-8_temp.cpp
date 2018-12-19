/*======================================================================
*        filename: 3-8_temp.cpp
*        author: rambogui
*        data: 2018-12-19 10:17:45
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;
    
    string str;
    getline(cin, str);

    string temp (str.size(), 'X');

    cout << temp << endl;

    return 0;
}
