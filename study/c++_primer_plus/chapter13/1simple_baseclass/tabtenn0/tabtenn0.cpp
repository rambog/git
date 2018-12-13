/*======================================================================
*        filename: tabtenn0.cpp
*        author: rambogui
*        data: 2018-12-11 08:38:39
======================================================================*/

#include <iostream>
#include "tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const string &fn,
    const string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
