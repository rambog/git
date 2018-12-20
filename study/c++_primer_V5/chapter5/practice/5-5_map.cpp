/*======================================================================
*        filename: 5-5_map.cpp
*        author: rambogui
*        data: 2018-12-20 21:10:59
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    const std::vector<std::string> scores = {
        "F", "D", "C", "B", "A", "A++"};
    unsigned grade;
    std::cin >> grade;

    if (grade < 60)
        std::cout << scores[0] << std::endl;
    else
        std::cout << scores[(grade-50)/10] << std::endl;

    return 0;
}
