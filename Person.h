#pragma once

#include "BookLink.h"
#include <iostream>
using namespace std;

#define ull unsigned long long

struct History {
    Book book;
    ull time;      // 借阅次数
    History* next;
};

class Person {
protected:
    ull id;
    string username;
    string password;

public:
    Person();
    Person(string newUsername, string newPassword);

    ull getID() const;
    string getUsername() const;
    void changePassword(string newPassword);
    void searchBook(BookLink* headMain);

    friend class BookLink;
};

//todo:虚函数
