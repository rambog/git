/*======================================================================
*        filename: switch_otherctrl.cpp
*        author: rambogui
*        data: 2018-12-20 21:44:53
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    bool b;

    switch (static_cast<int>(b)) {
        case true:
            while (1) ;
            break;
        case false:
            if (true)
                ;
            break;
        default:
            switch (true) {
            }
            break;
    }

    return 0;
}
