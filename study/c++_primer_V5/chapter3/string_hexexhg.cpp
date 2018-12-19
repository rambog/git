/*======================================================================
*        filename: string_hexexhg.cpp
*        author: rambogui
*        data: 2018-12-19 10:04:56
======================================================================*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by space. Hit ENTER when finished: "
         << endl;

    string result;
    string::size_type n;
    while (cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];

    cout << "Your hex number is: " << result << endl;

    return 0;
}
