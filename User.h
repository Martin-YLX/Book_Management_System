#pragma once

#include "Person.h"
#include <iostream>
using namespace std;

class User : public Person {
private:
    History* head;

public:
    User(string username, string password, ull id) : Person(username, password) {
        head = nullptr;
        this->id = id;
    }

    void borrowBook(string bookTitle);
    void returnBook(string bookTitle);
    void searchBook(string bookTitle);
    void searchHistory(string bookTitle);
};

class Admin : public Person {
public:
    Admin(string username, string password) : Person(username, password) {}

    void changeBook(string bookTitle);
    void changeUser(User& user);
};
