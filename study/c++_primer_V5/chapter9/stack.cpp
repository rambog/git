/*======================================================================
*        filename: stack.cpp
*        author: rambogui
*        data: 2018-12-28 08:46:53
======================================================================*/

#include <iostream>
#include <stack>

using std::stack;

int main(int argc, char *argv[])
{
    stack<int> intStack;

    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix);

    while (!intStack.empty()) {
        std::cout << intStack.top() << ' ';
        intStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
