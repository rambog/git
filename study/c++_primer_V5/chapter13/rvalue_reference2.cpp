/*======================================================================
*        filename: rvalue_reference2.cpp
*        author: rambogui
*        data: 2019-01-08 16:13:29
======================================================================*/

#include <iostream>
#include <string>

using std::string;

class StrVec {
public:
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(StrVec &&s) noexcept;
private:
    string *elements;
    string *first_free;
    string *cap;
};

StrVec::StrVec(StrVec &&s) noexcept :
    elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

int main(int argc, char *argv[])
{

    return 0;
}
