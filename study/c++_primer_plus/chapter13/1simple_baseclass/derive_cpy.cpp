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
    derveclass d1("I am very happy", "rambo", "gui");
    derveclass d2("I am a little happy", "yao", "gui");
    std::cout << std::endl;

    baseclass b1(d1);
    std::cout << std::endl;
    baseclass b2;
    b2 = d2;
    b1.show();
    b2.show();

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
