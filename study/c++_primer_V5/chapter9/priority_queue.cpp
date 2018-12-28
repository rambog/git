/*======================================================================
*        filename: priority_queue.cpp
*        author: rambogui
*        data: 2018-12-28 09:12:35
======================================================================*/

#include <iostream>
#include <cstdlib>
#include <queue>

using std::priority_queue;

int main(int argc, char *argv[])
{
    priority_queue<int> ipque;

    srand(0);
    int cnt = 10;
    for ( ; cnt != 0; --cnt)
        ipque.push(rand());

    while (!ipque.empty()) {
        std::cout << ipque.top() << ' ';
        ipque.pop();
    }
    std::cout << std::endl;

    return 0;
}
