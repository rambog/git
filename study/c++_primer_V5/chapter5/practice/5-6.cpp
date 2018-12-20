/*======================================================================
*        filename: 5-6.cpp
*        author: rambogui
*        data: 2018-12-20 21:19:28
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    unsigned grade; 
    std::string lettergrade;

    std::cin >> grade;

    lettergrade = (grade == 100 ? "A++" : 
                        (grade >= 90 ? "A" : 
                            (grade >= 80 ? "B" :
                                (grade >= 70 ? "C" :
                                    (grade >= 60 ? "D" : "F")))));
    std::cout << lettergrade << std::endl;

    return 0;
}
