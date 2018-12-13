/*======================================================================
*        filename: mytime0.h
*        author: rambogui
*        data: 2018-12-07 10:50:26
======================================================================*/

#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time &t) const;
    void Show() const;
};

#endif
