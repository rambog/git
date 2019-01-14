/*======================================================================
*        filename: Folder.h
*        author: rambogui
*        data: 2019-01-08 11:14:08
======================================================================*/

#ifndef __FOLDER_H_
#define __FOLDER_H_

#include <iostream>
#include <string>
#include <set>

#include "Message.h"

using std::endl;
using std::cout;
using std::cin;

class Folder {
friend class Message;
public:
    Folder() =default;

    void addMsg(const Message&);
    void remMsg(const Message&);
private:
    std::set<Message*> megs;
};

#endif
