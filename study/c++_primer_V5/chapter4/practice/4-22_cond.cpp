/*======================================================================
*        filename: 4-22_cond.cpp
*        author: rambogui
*        data: 2018-12-20 14:12:34
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    unsigned int grade;
    std::cin >> grade;
    std::string temp;

    temp = (grade >= 90) ? "high pass" :
                ((grade >= 75) ? "pass" :
                    ((grade >= 60) ? "low pass" : "fail"));

    std::cout << temp << std::endl;

    return 0;
}
