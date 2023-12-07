#pragma once

#include <iostream>
using namespace std;

#define ull unsigned long long
struct History {
    string title; //isbn号 issn号
    ull time; //借阅次数
    History *next;
};

class Person {
protected:
    ull id;
    string username;
    string password;
public:
    Person(string username,string password) {
        this->username = username;
        this->password = password;
    }

    void change_password(string new_password) {
        password = new_password;
    }

    string get_username() const {
        return username;
    }
};
