/*======================================================================
*        filename: Folder.cpp
*        author: rambogui
*        data: 2019-01-08 11:21:16
======================================================================*/

#include <iostream>

#include "Folder.h"

void Folder::addMsg(const Message& msg)
{
    megs.insert(&msg);
}

void Folder::remMsg(const Message& msg)
{
    megs.erase(&msg);
}
