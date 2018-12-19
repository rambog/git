/*======================================================================
*        filename: 3-8_for.cpp
*        author: rambogui
*        data: 2018-12-19 10:14:25
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    string str;
    getline(cin, str);

    for (decltype(str.size()) idx = 0; idx < str.size(); ++idx)
        str[idx] = 'X';
    cout << str << endl;
        
    return 0;
}
