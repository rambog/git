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
    void show() const;
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

void show(const baseclass &bc);

int main(int argc, char *argv[])
{
    baseclass b1;
    baseclass b2("rambo", "guii");
    //b1.show();
    //b2.show();
    show(b1);
    show(b2);

    std::cout << std::endl;
    std::cout << "Now use derive class\n" << std::endl;

    derveclass d1;
    derveclass d2("I am very happy", "gui", "yao");
    derveclass d3("I am a litter happy", b2);

    //d1.derveshow();
    //d2.derveshow();
    //d3.derveshow();
    show(d1);
    show(d2);
    show(d3);

    std::cout << std::endl;
    derveclass *pdc;
    pdc = (derveclass*)&b2;
    pdc->derveshow();
    std::cout << &b1 << ' ' << &b2 << std::endl;

    return 0;
}

baseclass::baseclass() : firstname("nonef"), lastname("nonel")
{
    std::cout << "def constructor!" << std::endl;
}

baseclass::baseclass(const std::string &fn, const std::string &ln) :
    firstname(fn), lastname(ln)
{
    std::cout << "par constructor!" << std::endl;
}

void baseclass::show() const
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
    std::cout << &content << std::endl;
}

void show(const baseclass &bc)
{
    bc.show();
}
