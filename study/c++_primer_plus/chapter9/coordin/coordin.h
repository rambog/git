/*======================================================================
*        filename: coordin.h
*        author: rambogui
*        data: 2018-12-03 08:24:09
======================================================================*/

#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
