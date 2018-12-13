/*======================================================================
*        filename: stonewt.h
*        author: rambogui
*        data: 2018-12-08 14:11:54
======================================================================*/

#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;
};

#endif
