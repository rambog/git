/*======================================================================
*        filename: 7-1.cpp
*        author: rambogui
*        data: 2018-12-22 13:51:37
======================================================================*/

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

struct Sales_data {
    string bookNo;
    unsigned units_sold;
    double revenue;
};

const string &isbin(const Sales_data &sd)
{
    return sd.bookNo;
}

Sales_data &combine(Sales_data &dst, const Sales_data &src)
{
    if (dst.bookNo != src.bookNo) return dst;

    dst.units_sold += src.units_sold;
    dst.revenue += src.revenue;
}

Sales_data add(const Sales_data &sd1, const Sales_data &sd2)
{
    Sales_data tmp = {"NULL", 0, 0.0};
    if (sd1.bookNo != sd2.bookNo) return tmp;

    tmp.units_sold = sd1.units_sold + sd2.units_sold;
    tmp.revenue = sd1.revenue + sd2.revenue;
    return tmp;
}

bool read(istream &is, Sales_data &sd)
{
    double price;
    if (is >> sd.bookNo >> sd.units_sold >> price) {
        sd.revenue = sd.units_sold * price;
        return true;
    }
    return false;
}

ostream &print(ostream &os, const Sales_data &sd)
{
    os << sd.bookNo << ' ' << sd.units_sold << ' ' << sd.revenue 
       << ' ' << sd.revenue/sd.units_sold;
    return os;
}

int main(int argc, char *argv[])
{
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (isbin(total) == isbin(trans))
                combine(total, trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        std::cerr << "No data?!" << endl;
    }
    return 0;
}
