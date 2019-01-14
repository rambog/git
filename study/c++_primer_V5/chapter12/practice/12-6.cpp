/*======================================================================
*        filename: 12-6.cpp
*        author: rambogui
*        data: 2019-01-14 14:42:17
======================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> *
vector_alloc()
{
    return (new std::vector<int>);
}

void
vector_scanf(std::istream &is, std::vector<int> *pive)
{
    int tmp;
    while (is >> tmp) {
        pive->push_back(tmp);
    }
}

void
vector_print(std::ostream &os, const std::vector<int> *pive)
{
    for_each(pive->begin(), pive->end(),
        [&os](const int &i)
        { os << i << ' '; });
}

void
vector_free(const std::vector<int> *pive)
{
    delete pive;
}

int main(int argc, char *argv[])
{
    std::vector<int> *pive = vector_alloc();

    vector_scanf(std::cin, pive);
    vector_print(std::cout, pive);

    vector_free(pive);

    return 0;
}
