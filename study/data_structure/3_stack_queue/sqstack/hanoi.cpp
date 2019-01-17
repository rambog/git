/*======================================================================
*        filename: hanoi.cpp
*        author: rambogui
*        data: 2019-01-17 22:41:46
======================================================================*/

#include <iostream>

void printline(int n, int top)
{
    if (top == 1) 
        std::cout << n << "    " << std::endl;
    else if (top == 2)
        std::cout << "  " << n << "  " << std::endl;
    else if (top == 3)
        std::cout << "    " << n << std::endl;
    else
        throw std::out_of_range(std::string("printline out of range"));
}

void hanoi(int n, int cur, int top)
{
    if (n == 1) {
        printline(n, top);
    }

    if (cur == 1)
        hanoi(n-1, 1, 2
}

int main(int argc, char *argv[])
{
    std::cout << "X Y Z" << std::endl;


    return 0;
}
