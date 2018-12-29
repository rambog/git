/*======================================================================
*        filename: 10-5.cpp
*        author: rambogui
*        data: 2018-12-29 09:16:56
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char *argv[])
{
    std::vector<const char *> roster1 = {"rambo", "guiyao"};
    std::vector<const char *> roster2 = {"rambo", "guiyao"};

    roster1.clear();
    roster2.clear();
    std::cout << roster1.size() << ' ' << roster2.size() << std::endl;

    char str11[] = "rambo", str12[] = "guiyao";
    char str21[] = "rambo", str22[] = "guiyao";
    roster1.push_back(str11);
    roster1.push_back(str12);

    roster2.push_back(str21);
    roster2.push_back(str22);

    if (equal(roster1.begin(), roster1.end(), roster2.begin()))
        std::cout << "equal\n";
    else
        std::cout << "not equal\n";

    for (auto tmp : roster1)
        std::cout << (void*)tmp << ' ';
    std::cout << std::endl;
    
    for (auto tmp : roster2)
        std::cout << (void*)tmp << ' ';
    std::cout << std::endl;

    return 0;
}
