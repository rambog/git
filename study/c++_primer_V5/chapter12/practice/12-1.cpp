/*======================================================================
*        filename: StrBlob.cpp
*        author: rambogui
*        data: 2019-01-14 13:21:42
======================================================================*/

#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); } 
    void pop_back();

    std::string& front();
    std::string& back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;

friend std::ostream& operator<<(std::ostream &os, const StrBlob& sb);
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) :
    data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string &
StrBlob::front() 
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &
StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::ostream& operator<<(std::ostream &os, const StrBlob& sb)
{
    for_each((sb.data)->begin(), (sb.data)->end(), [&os](const std::string s)
            { os << s << ' '; });
    return os;
}

int main(int argc, char *argv[])
{
    StrBlob b1;
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    return 0;
}
