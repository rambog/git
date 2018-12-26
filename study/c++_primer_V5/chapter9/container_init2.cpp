/*======================================================================
*        filename: container_init2.cpp
*        author: rambogui
*        data: 2018-12-26 08:59:01
======================================================================*/

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>

using std::string;
using std::vector;
using std::list;
using std::forward_list;
using std::deque;

int main(int argc, char *argv[])
{
    vector<int> ivec(10, -1);
    list<string> slst(10, "hi!");
    forward_list<int> ifwdl(10);
    deque<string> sdeq(10);

    vector<int>::const_iterator ivecbeg = ivec.begin();
    while (ivecbeg != ivec.end())
        std::cout << *ivecbeg++ << ' ';
    std::cout << std::endl;

    list<string>::const_iterator slstbeg = slst.begin();
    while (slstbeg != slst.end())
        std::cout << *slstbeg++ << ' ';
    std::cout << std::endl;

    forward_list<int>::const_iterator fwdlbeg = ifwdl.begin();
    while (fwdlbeg != ifwdl.begin())
        std::cout << *fwdlbeg++ << ' ';
    std::cout << std::endl;

    deque<string>::const_iterator deqbeg = sdeq.begin();
    while (deqbeg != sdeq.end())
        std::cout << *deqbeg++ << ' ';
    std::cout << std::endl;

    return 0;
}
