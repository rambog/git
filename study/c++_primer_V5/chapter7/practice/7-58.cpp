/*======================================================================
*        filename: 7-58.cpp
*        author: rambogui
*        data: 2018-12-25 14:01:18
======================================================================*/

#include <iostream>
#include <vector>
using std::vector;

class Example {
public:
    static double rate;
    static const int vecSize = 20;
    static vector<double> vec;
};

double Example::rate = 6.5;
const int Example::vecSize;
vector<double> Example::vec(vecSize);

int main(int argc, char *argv[])
{
    std::cout << Example::vecSize << std::endl;
    return 0;
}