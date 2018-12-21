/*======================================================================
*        filename: 6-17_2.cpp
*        author: rambogui
*        data: 2018-12-21 10:50:44
======================================================================*/

#include <iostream>
#include <cctype>

void strtoupper(std::string &str)
{
    std::string::iterator iter = str.begin();
    while (iter != str.end())  {
        if (!isupper(*iter))
            *iter = toupper(*iter);
            ++iter;
    }
}

int main(int argc, char *argv[])
{
    std::string temp("rambo");

    strtoupper(temp);
    std::cout << temp << std::endl;

    return 0;
}
