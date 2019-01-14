/*======================================================================
*        filename: 12-3.cpp
*        author: rambogui
*        data: 2019-01-14 13:46:18
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t);
    void pop_back();
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;

friend std::ostream& operator<<(std::ostream &os, const StrBlob &sb);
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : 
    data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::push_back(const std::string &t)
{
    data->push_back(t);
}

void StrBlob::pop_back()
{
    check(0, "pop back is empty");
    data->pop_back();
}

std::string &StrBlob::front()
{
    check(0, "front is empty");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "check is empty");
    return data->back();
}

#if 1
const std::string& StrBlob::front() const
{
    check(0, "front is empty");
    return data->front();
}

const std::string& StrBlob::back() const
{
    check(0, "back is empty");
    return data->back();
}
#endif

std::ostream& operator<<(std::ostream &os, const StrBlob &sb)
{
    for_each((sb.data)->begin(), (sb.data)->end(),
        [&os](const std::string &s) -> void
        { os << s << ' '; });
    return os;
}

int main(int argc, char *argv[])
{
    StrBlob strb1 = {"rambp", "giyao"};
    StrBlob strb2 = {"string", "vector", "stdexcpet"};
    StrBlob strbb1 = strb1;
    StrBlob strbb2 = strb2;

    std::cout << strb1 << std::endl;
    std::cout << strbb1 << std::endl;
    std::cout << strb2 << std::endl;
    std::cout << strbb2 << std::endl;

    return 0;
}
