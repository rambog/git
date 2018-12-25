/*======================================================================
*        filename: 8-1.cpp
*        author: rambogui
*        data: 2018-12-25 14:45:41
======================================================================*/

#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;

istream &print(istream &is)
{
    std::string str;
    while (cin >> str) {
        std::cout << str << ' ';
        if (str == "q") break;
    }
    std::cout << std::endl;

    istream::iostate now = is.rdstate();

    if (now & istream::failbit) {
        now &= ~(istream::failbit);
        std::cout << "istream failbit set\n";
    } 
    if (now & istream::badbit) {
        now &= ~(istream::badbit);
        std::cout << "istream badbit set\n";
    } 
    if (now & istream::eofbit) {
        now &= ~(istream::eofbit);
        std::cout << "istream eofbit set\n";
    } 
    if (now & istream::goodbit) {
        now &= ~(istream::goodbit);
        std::cout << "istream goodbit set\n";
    } 

    //is.setstate(now);
    is.clear();
    return is;
}

int main(int argc, char *argv[])
{
    std::string temp;
    //print(cin) >> temp;
    //std::cout << "In main temp:" << temp << std::endl;
    if (print(cin))
        std::cout << "print ret istream is good status\n";
    return 0;
}
