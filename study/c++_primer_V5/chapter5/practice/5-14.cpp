/*======================================================================
*        filename: 5-14.cpp
*        author: rambogui
*        data: 2018-12-20 22:08:11
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string max_str;
    unsigned max = 0;
    std::string tmp_str;
    std::string cur_str;
    unsigned tmp = 0;

    while (std::cin >> cur_str) {
        if (tmp_str != cur_str) {
            tmp_str = cur_str;
            tmp = 1;
        } else
            ++tmp;

        if (max < tmp) {
            max = tmp;
            max_str = tmp_str;
        }
    }

    std::cout << max << ' ' << max_str << std::endl;

    return 0;
}
