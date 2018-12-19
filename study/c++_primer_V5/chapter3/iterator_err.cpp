/*======================================================================
*        filename: iterator_err.cpp
*        author: rambogui
*        data: 2018-12-19 15:34:46
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::string str("rambo");
    std::string::const_iterator iter1;
    std::string::const_iterator iter2;
    std::vector<int> ivec;
    std::vector<int>::iterator ite1;
    std::vector<int>::iterator ite2;

    iter1 = str.cbegin();
    str = "guiyao";
    iter2 = str.cbegin();

    if (iter2 == iter1)
        std::cout << "iter1 == iter2\n";
    else
        std::cout << "iter1 != iter2\n";


    ite1 = ivec.begin();
    ivec.push_back(1);
    ite2 = ivec.begin();
    if (ite2 != ite1)
        std::cout << "ite1 != ite2\n";

    return 0;
}
