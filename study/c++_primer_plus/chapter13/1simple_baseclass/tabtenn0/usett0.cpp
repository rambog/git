/*======================================================================
*        filename: usett0.cpp
*        author: rambogui
*        data: 2018-12-11 08:47:43
======================================================================*/

#include <iostream>
#include "tabtenn0.h"

int main(int argc, char *argv[])
{
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();
    if (player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    return 0;
}
