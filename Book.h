#pragma once

#include <iostream>
using namespace std;

struct  Tag {
    string name;
    Tag *next;

    void add(string s);
    void sub(string s);
};

#define ull unsigned long long
struct Detail {
    string name;
    ull isbn_issn;
    string author;
    string publish;
    ull publish_time;
    double price;
    ull time;
    Tag *head = nullptr;

    Detail(string nam,ull isbn,string auth,string pub,ull pub_time,double pri,ull tim);
    void change_tag(string s); // 0 add 1 sub
    void add_time();
    
};

class Book {
private:
    Detail detail;
    Book *next;
public:
    Book();
    void add();
    void sub();
    void change();
};