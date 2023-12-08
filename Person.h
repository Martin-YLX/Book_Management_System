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
    Person(string username, string password);

    ull getID() const;
    string getUsername() const;
    void changePassword(string password);
    void searchBook(BookLink* headMain);

    friend class BookLink;
};

