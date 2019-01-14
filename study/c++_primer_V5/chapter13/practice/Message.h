/*======================================================================
*        filename: Message_Folder.h
*        author: rambogui
*        data: 2019-01-08 10:35:48
======================================================================*/

#ifndef __MESSAGE_H_
#define __MESSAGE_H_

#include <iostream>
#include <string>
#include <set>

#include "Folder.h"

using std::endl;
using std::cout;
using std::cin;

class Message {
friend class Folder;
public:
    explicit Message(const std::string &str = "") :
        contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

#endif
