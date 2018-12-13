/*======================================================================
*        filename: derive_tst.cpp
*        author: rambogui
*        data: 2018-12-11 09:06:57
======================================================================*/

#include <iostream>

class baseclass
{
private:
    std::string firstname;
    std::string lastname;
public:
    baseclass();
    baseclass(const std::string &fn, const std::string &ln);
    void show();
};

class derveclass : public baseclass
{
private:
    std::string content;
public:
    derveclass();
    derveclass(const std::string &ct, const std::string &fn,
        const std::string &ln);
    derveclass(const std::string &ct, const baseclass &bs);
    void derveshow();
};

int main(int argc, char *argv[])
{
    baseclass b1;
    baseclass b2("rambo", "gui");
    b1.show();
    b2.show();

    std::cout << std::endl;
    std::cout << "Now use derive class" << std::endl;

    derveclass d1;
    derveclass d2("I am very happy", "gui", "yao");
    derveclass d3("I am a litter happy", b2);

    d1.derveshow();
    d2.derveshow();
    d3.derveshow();

    return 0;
}

baseclass::baseclass() : firstname("none"), lastname("none")
{
    std::cout << "def constructor!" << std::endl;
}

baseclass::baseclass(const std::string &fn, const std::string &ln) :
    firstname(fn), lastname(ln)
{
    std::cout << "par constructor!" << std::endl;
}

void baseclass::show()
{
    std::cout << firstname << ", " << lastname << std::endl;
    std::cout << &firstname << " " << &lastname << std::endl;
}

derveclass::derveclass() : content("none") {}

#if 1
derveclass::derveclass(const std::string &ct, const std::string &fn,
    const std::string &ln) : content(ct) , baseclass(fn, ln) {}
#else
derveclass::derveclass(const std::string &ct, const std::string &fn,
    const std::string &ln) : content(ct) { baseclass(fn, ln); }
#endif

#if 1
derveclass::derveclass(const std::string &ct, const baseclass &bs) :
    content(ct) , baseclass(bs) {}
#else
derveclass::derveclass(const std::string &ct, const baseclass &bs) :
    content(ct) {}
#endif

void derveclass::derveshow()
{
    show();
    std::cout << content << std::endl;
}
