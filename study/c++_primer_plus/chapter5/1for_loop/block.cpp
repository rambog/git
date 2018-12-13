/*======================================================================
*        filename: block.cpp
*        author: rambogui
*        data: 2018-11-27 10:24:38
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    cout << "The Amazing Accounto will sum and average ";
    cout << "five numbers for you.\n";
    cout << "Please enter five value:\n";
    double number;
    double sum = 0.0;
    for (int i = 1; i <=5; i++)
    {
        cout << "Value " << i << ": " ;
        cin >> number;
        sum += number;
    }

    cout << "Five exquisite choices indeed! ";
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum/5 << ".\n";
    cout << "The Amazing Accounto bids you adieu!\n";

    return 0;
}
