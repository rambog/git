/*======================================================================
*        filename: 6-17_1.cpp
*        author: rambogui
*        data: 2018-12-21 10:45:31
======================================================================*/

#include <iostream>
#include <string>

int uppernum(const std::string& str)
{
    unsigned cnt = 0;
    std::string::const_iterator iter = str.begin();
    while (iter != str.end()) {
        if (isupper(*iter++))
            ++cnt;
    }

    return cnt;
}

int main(int argc, char *argv[])
{
    std::cout << uppernum("ramboaioeaio") << std::endl;
    return 0;
}
