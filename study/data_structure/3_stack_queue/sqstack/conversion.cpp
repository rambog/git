/*======================================================================
*        filename: conversion.cpp
*        author: rambogui
*        data: 2019-01-17 15:16:39
======================================================================*/

#include <iostream>
#include "sqstack.h"

const static unsigned d = 2;

int main(int argc, char *argv[])
{
    stack<int> result;

    int i = 1348; 

    while (i) {
        result.push(i%d);
        i /= d;
    }

    std::cout << "before: " << result << std::endl;
    int tmp = 0;
    while (!result.empty()) {
        result.pop(tmp);
        std::cout << tmp;
    }
    std::cout << std::endl;
    std::cout << "after: " << result << std::endl;
    return 0;
}
