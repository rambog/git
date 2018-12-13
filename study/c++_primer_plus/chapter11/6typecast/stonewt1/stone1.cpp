/*======================================================================
*        filename: stone1.cpp
*        author: rambogui
*        data: 2018-12-08 15:00:27
======================================================================*/

#include <iostream>
#include "stonewt1.h"

int main(int argc, char *argv[])
{
    using std::cout;

    Stonewt poppins(9, 2.8);
    double p_wt = poppins;

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << (int)poppins << " pounds.\n";

    return 0;
}
