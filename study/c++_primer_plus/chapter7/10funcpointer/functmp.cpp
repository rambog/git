/*======================================================================
*        filename: functmp.cpp
*        author: rambogui
*        data: 2018-11-29 19:13:36
======================================================================*/

#include <iostream>

const double * f1(const double *, int n);
const double * f2(const double *, int n);
const double * f3(const double *, int n);

int main(int argc, char *argv[])
{
    using namespace std;
    const double *(*pf1)(const double *, int);
    const double *(*pf2)(const double *, int);
    const double *(*pf3)(const double *, int);

    double tmp;

    tmp = 3.0;
    pf1 = f1;
    cout << *(*pf1)(&tmp,0) << endl; 

    pf2 = f2;
    cout << *(*pf2)(&tmp,0) << endl;

    pf3 = f3;
    cout << *(*pf3)(&tmp,0) << endl;

    const double *(*pa[3])(const double *, int) = {pf1, pf2, pf3};
    tmp = 4.5;
    cout << *(*pa[0])(&tmp, 0) << ' ' << *(*pa[1])(&tmp, 0) << ' ' << *(*pa[2])(&tmp, 0) << endl;

    const double *(*(*pb)[3])(const double *, int) = &pa;
    tmp = 6;
    cout << *(*(*pb)[0])(&tmp, 0) << ' ' << *(*(*pb)[1])(&tmp, 0) << ' ' << *(*(*pb)[2])(&tmp, 0) << endl;

    const double *(**pc[3])(const double *, int) = {&pf1, &pf2, &pf3};

    tmp = 7.5;
    cout << *(**(pc[0]))(&tmp, 0) << ' ' << *(**(pc[1]))(&tmp, 0) << ' ' << *(**(pc[2]))(&tmp, 0) << endl;

    int foo[3] = {1, 2, 3};
    int (*pfoo)[3] = &foo;
    cout << (*pfoo)[0] << ' ' << (*pfoo)[1] << ' ' << (*pfoo)[2] << endl;
    int too[3] = {4, 5, 6};
    pfoo = (int (*)[3])too;
    cout << (*pfoo)[0] << ' ' << (*pfoo)[1] << ' ' << (*pfoo)[2] << endl;

    return 0;
}

const double * f1(const double *pd, int n)
{
    return pd;
}
const double * f2(const double *pd, int n)
{
    return pd;
}
const double * f3(const double *pd, int n)
{
    return pd;
}
