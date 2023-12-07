#pragma once

#include <iostream>
using namespace std;

struct Tag {
    int num;
    string name;
    Tag* pre;
    Tag* next;
};

class BookLink;

#define ull unsigned long long

class Book {
private:
    string title;
    string isbn_issn;
    string author;
    string publish;
    string publish_time;
    string price;
    ull time;
    Tag* head;

public:
    Book(); // 初始化
    Book(string tit, string isbn, string auth, string pub, string pub_time, string pri, ull tim); // 插入内容
    void insert_tag(string s); // 增加 tag
    void delete_tag(string s); // 删除 tag
    void add_time(int x); // 修改借阅次数

    // 添加 getter 函数，用于获取私有成员
    string getTitle() const;
    string getIsbnIssn() const;
    string getAuthor() const;
    string getPublish() const;
    string getPublishTime() const;
    string getPrice() const;
    ull getTime() const;
    Tag* getHead() const;

    friend class BookLink;
};

class BookLink {
private:
    int num;
    Book detail;
    BookLink* pre;
    BookLink* next;

public:
    BookLink(); // 初始化
    void print(); // 输出全部信息
    void insert(Book in); // 插入 Detail
    bool check(string isbn); // 验证 isbn issn
    // 构建
    void changeBook(); // 修改 Book
    void insertBook(Book in); // 增加 Book
    void deleteBook(string isbn); // 减少 Book
    // 查询
    void searchBook(); // 寻找 Book
    void searchName(BookLink* now); // 按名称查询
    void searchIsbn(BookLink* now); // 按 ISBN 查询
    void searchAuthor(BookLink* now); // 按作者查询
    void searchPublish(BookLink* now); // 按出版社查询
    void searchPublishTime(BookLink* now); // 按出版时间查询
    void searchPrice(BookLink* now); // 按价格查询
    void searchTag(BookLink* now); // 按标签查询
    // 修改
    void changeName(BookLink* now); // 修改名称
    void changeIsbn(BookLink* now); // 修改 ISBN
    void changeAuthor(BookLink* now); // 修改作者
    void changePublish(BookLink* now); // 修改出版社
    void changePublishTime(BookLink* now); // 修改出版时间
    void changePrice(BookLink* now); // 修改价格
    // 排序
    void sortTime(); // 按借阅次数排序
    static bool cmpPublishTime(string a, string b); // 比较出版时间
    void sortPublishTime(); // 按出版时间排序
    void merge(BookLink*& head1, BookLink*& head2); // 合并两个链表
    void sortLexico(); // 字典序排序
};
