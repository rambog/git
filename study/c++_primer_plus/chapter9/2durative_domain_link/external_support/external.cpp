/*======================================================================
*        filename: external.cpp
*        author: rambogui
*        data: 2018-12-03 11:08:54
======================================================================*/

#include <iostream>
using namespace std;

double warming = 0.3;

void update(double dt);
void local();

int main(int argc, char *argv[])
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degress.\n";
    return 0;
}


