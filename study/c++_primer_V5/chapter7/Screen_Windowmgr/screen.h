/*======================================================================
*        filename: screen.h
*        author: rambogui
*        data: 2018-12-24 10:32:43
======================================================================*/

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr {
public:
    typedef std::vector<Screen>::size_type ScreenIndex;

    Window_mgr();
    
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens/*{Screen(24, 80, ' ')}*/;
};



class Screen {
public:
    typedef std::string::size_type pos;

    Screen() =default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
        contents(ht*wd, c) { }
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') { }

    char get() const
        { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os)
        { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
        { do_display(os); return *this; }

    pos size() const;
    //typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    
    void do_display(std::ostream &os) const { os << contents; }

//friend class Window_mgr;
friend void Window_mgr::clear(ScreenIndex);
};
