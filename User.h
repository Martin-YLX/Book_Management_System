#pragma once

#include "Person.h"

class User : public Person {
private:
    History* headHistory;
    BookLink* borrowed;

    User* pre;
    User* next;

public:
    User(string username, string password, ull id);

    User* getPre();
    User* getNext();
    void insertPre(User* user);
    void insertNext(User* user);

    void print();
    void borrowBook(BookLink* headMain);
    void returnBook();
    void searchBook(BookLink* headMain);
};

class Admin : public Person {
public:
    Admin(string username, string password) : Person(username, password) {}

    void changeBook(BookLink* headMain);

    // User
    void insertUser(User* userHead);
    void deleteUser(User* userHead,ull id);
    void resetUser(User* userHead,ull id);
    void searchUser(User* userHead,ull id);

    friend class User;
};

class Visitor : public Person {
public:
    void searchBook(BookLink* headMain);
};