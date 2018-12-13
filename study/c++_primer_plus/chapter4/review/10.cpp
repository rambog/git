/*======================================================================
*        filename: 10.cpp
*        author: rambogui
*        data: 2018-11-27 08:40:57
======================================================================*/

#include <iostream>

enum Response
{
    No, Yes, Maybe
};

enum Response1
{
    Yes1 = 1, No1 = 0, Maybe1 = 2
};

enum Response2
{
    Yes2 = -3, No2, Maybe2
};

int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;

    cout << No << " " << Yes << " " << Maybe << endl;
    cout << No1 << " " << Yes1 << " " << Maybe1 << endl;
    cout << No2 << " " << Yes2 << " " << Maybe2 << endl;

    return 0;
}
