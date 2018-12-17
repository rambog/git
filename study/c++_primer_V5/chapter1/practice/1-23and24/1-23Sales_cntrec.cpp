/*======================================================================
*        filename: 1-23Sales_cntrec.cpp
*        author: rambogui
*        data: 2018-12-17 16:13:46
======================================================================*/

#include <iostream>
#include <cstring>
#include "Sales_item.h"

class Cnt_Sales
{
private:
    enum { ADDSTEP = 10};
    struct isbn_record
    {
        std::string isbn;
        int record_cnt;
    };
    isbn_record *record_table;
    int mem_cnt;
    int use;
    void addmem();
public:
    explicit Cnt_Sales(int initcnt = ADDSTEP);
    Cnt_Sales(const Cnt_Sales &cs);
    ~Cnt_Sales();

    Cnt_Sales& operator= (const Cnt_Sales &cs);

    void addrecord(const Sales_item &record);
    void show();
};

int main(int argc, char *argv[])
{
    Sales_item temp;
    Cnt_Sales cnt;

    while (std::cin >> temp) 
        cnt.addrecord(temp);

    cnt.show();

    return 0;
}

void Cnt_Sales::addmem()
{
    mem_cnt += ADDSTEP;
    isbn_record *temp = new isbn_record[mem_cnt];
    std::memcpy(temp, record_table, sizeof(isbn_record)*use);
    delete [] record_table;
    record_table = temp;
}

Cnt_Sales::Cnt_Sales(int initcnt) : mem_cnt(initcnt), use(0)
{
    record_table = new isbn_record[initcnt];
}

Cnt_Sales::Cnt_Sales(const Cnt_Sales &cs)
{
    mem_cnt = cs.mem_cnt;
    use = cs.use;
    record_table = new isbn_record[mem_cnt];
    std::memcpy(record_table, cs.record_table, sizeof(isbn_record)*use); 
}

Cnt_Sales::~Cnt_Sales()
{
    delete [] record_table;
}

Cnt_Sales& Cnt_Sales::operator= (const Cnt_Sales &cs)
{
    if (this == &cs) return *this;

    delete [] record_table;
    mem_cnt = cs.mem_cnt;
    use = cs.use;
    record_table = new isbn_record[mem_cnt];
    std::memcpy(record_table, cs.record_table, sizeof(isbn_record)*use); 
}

void Cnt_Sales::addrecord(const Sales_item &record)
{
    int i = 0;
    for (i = 0; i < use; i++) {
        if (record_table[i].isbn == record.Isbn()) {
            record_table[i].record_cnt++;
            return;
        }
    }

    if (use >= mem_cnt)
        addmem();
    
    ++use;
    record_table[i].isbn = record.Isbn();
    record_table[i].record_cnt++;
}

void Cnt_Sales::show()
{
    for (int i = 0; i < use; i++) {
        std::cout << "isbn: " << record_table[i].isbn;
        std::cout << ". record_cnt: " << record_table[i].record_cnt;
        std::cout << std::endl;
    }
}
