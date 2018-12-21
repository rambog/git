/*======================================================================
*        filename: str_subrange.cpp
*        author: rambogui
*        data: 2018-12-21 14:27:02
======================================================================*/

#include <iostream>
#include <string>

bool str_subrange(const std::string &str1, const std::string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;
    std::string::size_type size = (str1.size() < str2.size()) ?
                                    str1.size() : str2.size();

    for (std::string::size_type i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{

    return 0;
}
