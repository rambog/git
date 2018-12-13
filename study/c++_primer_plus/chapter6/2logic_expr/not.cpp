/*======================================================================
*        filename: not.cpp
*        author: rambogui
*        data: 2018-11-28 09:20:41
======================================================================*/

#include <iostream>
#include <climits>

bool is_int(double);

int main(int argc, char *argv[])
{
    using namespace std;

    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while (!is_int(num)) {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int(num);
    cout << "You've entered the integer " << val << "\nBye\n";

    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN)
        return true;
    else 
        return false;
}
