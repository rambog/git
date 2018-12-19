/*======================================================================
*        filename: getline.cpp
*        author: rambogui
*        data: 2018-12-19 09:11:19
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    using namespace std;

    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;

    return 0;
}
