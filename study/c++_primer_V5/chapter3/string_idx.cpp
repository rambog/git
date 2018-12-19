/*======================================================================
*        filename: string_idx.cpp
*        author: rambogui
*        data: 2018-12-19 09:59:42
======================================================================*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    string temp;
    getline(cin, temp);

    for (auto &c : temp)
        if (isspace(c))
            break;
        else
            c = toupper(c);

    std::cout << temp << std::endl;

    return 0;
}
