/*======================================================================
*        filename: deque_rm.cpp
*        author: rambogui
*        data: 2018-12-27 09:13:29
======================================================================*/

#include <iostream>
#include <deque>

int main(int argc, char *argv[])
{
    std::deque<int> ideq(10, 11);

    for (auto tmp : ideq)
        std::cout << tmp << ' ';
    std::cout << std::endl;

    std::cout << &ideq[0] << std::endl;
    ideq.erase(ideq.begin()+1);
    std::cout << &ideq[0] << std::endl;

    return 0;
}
