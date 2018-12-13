/*======================================================================
*        filename: calling.cpp
*        author: rambogui
*        data: 2018-11-29 08:37:02
======================================================================*/
//calling.cpp -- defining, prototyping, and calling a function
#include <iostream>

void simple();  //function prototype

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "main() will call the simple() function:\n";
    simple();   //function call
    cout << "main() is finished with the simple() function.\n";

    return 0;
}

//function definition
void simple()
{
    using namespace std;

    cout << "I'm but a simple function.\n";
}
