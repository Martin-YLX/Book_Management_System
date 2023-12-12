#pragma once

#include "Person.h"

class User : public Person {
private:
    History* headHistory;
    BookLink* borrowed;

    User* pre;
    User* next;

public:
    User();
    User(string username, string password, ull id);

    User* getPre() const;
    User* getNext() const;
    void insertPre(User* user);
    void insertNext(User* user);

    void print();
    void borrowBook(BookLink* headMain);
    void returnBook();

    ~User();
};

class Admin : public Person {
public:
    Admin(string username, string password);

    void changeBook(BookLink* headMain);
    void deleteBook(BookLink* headMain);

    // User
    void insertUser(User* userHead);
    void deleteUser(User* userHead,ull id);
    void resetUser(User* userHead,ull id);
    void searchUser(User* userHead,ull id);

    friend class User;
};

class Visitor : public Person {
public:
};

//todo:最后优化：history添加变量追踪最后一个元素，提高效率