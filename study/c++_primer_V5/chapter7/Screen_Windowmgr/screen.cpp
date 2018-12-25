/*======================================================================
*        filename: screen.cpp
*        author: rambogui
*        data: 2018-12-24 10:46:17
======================================================================*/

#include <iostream>
#include <string>
#include "screen.h"

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

Screen::pos Screen::size() const
{
    return height*width;
}



/* window_mgr */
Window_mgr::Window_mgr()
{
    screens.push_back(Screen(24, 80, ' '));
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

