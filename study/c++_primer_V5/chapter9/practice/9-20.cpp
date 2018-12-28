/*======================================================================
*        filename: 9-20.cpp
*        author: rambogui
*        data: 2018-12-27 08:15:20
======================================================================*/

#include <iostream>
#include <list>
#include <deque>

using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    int temp;
    list<int> lst;
    deque<int> odd, even;

    while (cin >> temp)
        lst.push_back(temp);

    for (int tmp : lst)
        if (tmp % 2 == 0)
            even.push_back(tmp);
        else
            odd.push_back(tmp);

    deque<int>::const_iterator iter;
    for (iter = even.begin(); iter != even.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    for (iter = odd.begin(); iter != odd.end(); iter++)
        cout << *iter << ' ';
    cout << endl;

    return 0;
}
