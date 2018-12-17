/*======================================================================
*        filename: continue_num.cpp
*        author: rambogui
*        data: 2018-12-17 14:33:49
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    int currVal = 0, val = 0;
    int cnt = 0;

    while (std::cin >> val) {
        if (cnt == 0) {
            currVal = val;
            ++cnt;
            continue;
        }

        if (currVal == val)
            ++cnt;
        else {
            std::cout << currVal << " occurs "
                      << cnt << " times" << std::endl;
            currVal = val;
            cnt = 1;
        }
    }

    if (cnt != 0) 
        std::cout << currVal << " occurs " 
                  << cnt << " times" << std::endl;

    return 0;
}
