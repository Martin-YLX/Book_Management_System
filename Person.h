#pragma once

#include <iostream>
using namespace std;

#define ull unsigned long long

struct History {
    string title; // ISBN号 ISSN号
    ull time;      // 借阅次数
    History* next;
};

class Person {
protected:
    ull id;
    string username;
    string password;

public:
    Person(string username, string password) {
        this->username = username;
        this->password = password;
    }

    void changePassword(string password) {
        this->password = password;
    }

    string getUsername() const {
        return username;
    }
};

