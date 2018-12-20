/*======================================================================
*        filename: 4-22_ifelse.cpp
*        author: rambogui
*        data: 2018-12-20 14:08:38
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    unsigned int temp;
    std::cin >> temp;
    std::string grade;

    if (temp >= 90)
        grade = "high pass";
    else if (temp >= 75)
        grade = "pass";
    else if (temp >= 60)
        grade = "low pass";
    else
        grade = "fail";

    std::cout << grade << std::endl;
    
    return 0;
}
