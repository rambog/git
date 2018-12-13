/*======================================================================
*        filename: arrfun1.cpp
*        author: rambogui
*        data: 2018-11-29 11:33:53
======================================================================*/

#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);
int main(int argc, char *argv[])
{
    using namespace std;

    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";

    return 0;
}

int sum_arr(int arr[], int n)
{
    using namespace std;
    cout << sizeof arr << endl;

    int total = 0;
    for (int i = 0; i < n; i++)
        total = total + arr[i];

    return total;
}
