/*======================================================================
*        filename: bracket_pick.cpp
*        author: rambogui
*        data: 2019-01-17 15:58:01
======================================================================*/

#include <iostream>
#include "sqstack.h"

void bracket_pick(const char *p)
{
    stack<char> bs;
    char tmp;
    while (*p != 0x00) {
        if (*p == '{' || *p == '[' || *p == '(')
            bs.push(*p);
        else {
            if (!bs.get_top(tmp)) break; 

            if (*p == '}' && tmp == '{' ||
                *p == ']' && tmp == '[' ||
                *p == ')' && tmp == '(')
                bs.pop(tmp);
            else
                break;
        }
        p++;
    }

    if (*p == 0x00 && bs.empty())
        std::cout << "right\n";
    else
        std::cout << "error\n";
}

int main(int argc, char *argv[])
{
    bracket_pick("{{{}{{}}}}");
    bracket_pick("}{}{}{");
    
    bracket_pick("}{}{}");
    bracket_pick("{{}{}");

    bracket_pick("{}{}{}}");
    bracket_pick("{}{}{}{");

    bracket_pick("{}{{]{}}");
    return 0;
}
