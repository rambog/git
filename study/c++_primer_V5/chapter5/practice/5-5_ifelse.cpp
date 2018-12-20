/*======================================================================
*        filename: 5-5_ifelse.cpp
*        author: rambogui
*        data: 2018-12-20 21:15:33
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    unsigned grade;
    std::string lettergrade;
    std::cin >> grade;

    if (grade == 100)
        lettergrade = "A++";
    else if (grade >= 90)
        lettergrade = "A";
    else if (grade >= 80)
        lettergrade = "B";
    else if (grade >= 70)
        lettergrade = "C";
    else if (grade >= 60)
        lettergrade = "D";
    else
        lettergrade = "F";

    std::cout << lettergrade << std::endl;

    return 0;
}
