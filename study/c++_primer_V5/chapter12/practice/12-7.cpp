/*======================================================================
*        filename: 12-7.cpp
*        author: rambogui
*        data: 2019-01-14 14:51:15
======================================================================*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;

shared_ptr<vector<int>>
vector_alloc()
{
    return std::make_shared<vector<int>>();
}

void vector_scanf(shared_ptr<vector<int>> spvec)
{
    int tmp;
    while (cin >> tmp) {
        spvec->push_back(tmp);
    }
}

void vector_print(shared_ptr<vector<int>> spvec)
{
    for_each(spvec->begin(), spvec->end(),
        [](const int &i) { cout << i << ' '; });
}

int main(int argc, char *argv[])
{
    shared_ptr<vector<int>> spivec = vector_alloc();

    vector_scanf(spivec);
    vector_print(spivec);
    cout << endl;

    return 0;
}
