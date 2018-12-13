/*======================================================================
*        filename: arrfun4.cpp
*        author: rambogui
*        data: 2018-11-29 14:27:49
======================================================================*/

#include <iostream>
const int ArSize = 8;
int sum_arr(const int *begin, const int *end);
int main(int argc, char *argv[])
{
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sum_arr(cookies, cookies+ArSize);
    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eaters ate " << sum << " cookies.\n";
    
    sum = sum_arr(cookies + 4, cookies + 8);
    cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}

int sum_arr(const int *begin, const int *end)
{
    using namespace std;
    const int *pt;
    int total = 0;

    //*((int*)begin) = 0;
    *begin = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;

    return total;
}
