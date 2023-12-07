#pragma once

#include "Person.h"
#include <iostream>
using namespace std;

class User : public Person {
private:
    History *head;
public:
    User(string username,string password,ull id) : Person(username,password) {
        head = nullptr;
        this->id = id;
    } // 全局cnt ？ 前一成员id
    void borrow_book(string book_title);
    void return_book(string book_title);
    void search_book(string book_title);
    void search_history(string book_title);
};

class Admin : public Person {
public:
    Admin(string username,string password) : Person(username,password) {}
    void change_book(string book_title);
    void change_user(User& user);
};
