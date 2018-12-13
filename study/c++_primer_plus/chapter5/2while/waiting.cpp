/*======================================================================
*        filename: waiting.cpp
*        author: rambogui
*        data: 2018-11-27 13:57:33
======================================================================*/

#include <iostream>
#include <ctime>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";
    clock_t start = clock();
    while (clock() - start < delay)
        ;

    cout << "done \a\n";

    return 0;
}
