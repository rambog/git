/*======================================================================
*        filename: person.h
*        author: rambogui
*        data: 2018-12-22 16:06:41
======================================================================*/

#include <string>

class Person {
private:
    std::string name;
    std::string address;

public:
    Person() =default;
    Person(const std::string &n, const std::string &a) :
        name(n), address(a) { }
    Person(std::istream &);

    std::string get_name() const { return name; }
    std::string get_addr() const { return address; }

friend std::istream &person_read(std::istream &is, Person &item);
friend std::ostream &person_print(std::ostream &os, const Person &item);
};
