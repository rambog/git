/*======================================================================
*        filename: find_char.cpp
*        author: rambogui
*        data: 2018-12-21 09:41:50
======================================================================*/

#include <iostream>
#include <string>

std::string::size_type find_char(const std::string &s, char c,
                                    std::string::size_type &occurs)
{
    std::string::size_type ret = s.size();
    occurs = 0;
    for (std::string::size_type i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }

    return ret;
}


int main(int argc, char *argv[])
{
    std::string temp;

    std::string::size_type n;

    getline(std::cin, temp);
    find_char(temp, temp[0], n);
    std::cout << temp << std::endl;
    std::cout << temp[0] << ' ' << n << std::endl;

    return 0;
}
