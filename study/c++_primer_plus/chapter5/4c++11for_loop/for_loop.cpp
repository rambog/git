/*======================================================================
*        filename: for_loop.cpp
*        author: rambogui
*        data: 2018-11-27 14:18:54
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
    for (double x : prices)
        cout << x << " ";
    cout << endl;

    for (double &x : prices)
        x = x*0.80;

    for (int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++)
        cout << prices[i] << " ";
    cout << endl;

    for (int x : {3, 5, 2, 8, 6})
        cout << x << " ";
    cout << endl;

    return 0;
}
