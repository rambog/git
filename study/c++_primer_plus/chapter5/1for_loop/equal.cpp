/*======================================================================
*        filename: equal.cpp
*        author: rambogui
*        data: 2018-11-27 11:11:50
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int quizscores[10] = 
        { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++)
        cout << "quiz " << i << " is a 20\n";

    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[1] = 20; i++)
        cout << "quiz " << i << " is a 20\n";

    return 0;
}
