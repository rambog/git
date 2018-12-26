/*======================================================================
*        filename: container_init.cpp
*        author: rambogui
*        data: 2018-12-26 08:48:01
======================================================================*/

#include <iostream>
#include <list>
#include <vector>
#include <forward_list>

using std::list;
using std::vector;
using std::forward_list;
using std::string;

int main(int argc, char *argv[])
{
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char *> articles = {"a", "an", "the"};

    list<string> list2(authors);

    forward_list<string> words(articles.begin(), articles.end());

    return 0;
}
