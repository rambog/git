/*======================================================================
*        filename: express.cpp
*        author: rambogui
*        data: 2018-11-27 09:43:18
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    int x;
    
    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;

    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout.setf(ios_base::boolalpha);
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;

    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout << (bool)1 << endl;
    return 0;
}
