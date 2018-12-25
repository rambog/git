/*======================================================================
*        filename: 7-44.cpp
*        author: rambogui
*        data: 2018-12-25 11:02:50
======================================================================*/

#include <iostream>
#include <vector>
#include <string>

class NoDefault {
public:
    //NoDefault(const std::string &s) : nostr(s) {}
    NoDefault(const std::string &s = "") : nostr(s) {}
private:
    std::string nostr;
};

int main(int argc, char *argv[])
{
    std::vector<NoDefault> vec(10);
    return 0;
}
